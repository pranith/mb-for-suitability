/* This is the main function file.
 * All other code links with this.
 * The main function takes a bunch
 * of parameters and calls the
 * proper microbenchmark function.
 *
 *
 * par - parallelized version
 * seq - sequential version
 */

#include <omp.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <assert.h>
#include <pthread.h>

#include "main.h"

// 2 MB for each object 2 * 1024 * 1024 / sizeof(int)
#define MAX_ELEMENTS 524288

// batch size is equal to a cache block size
int BATCH_SIZE=16;
#undef ACCESSES
//#define ACCESSES 1000000000
#define ACCESSES 100000000

using namespace std;

class thread_object
{
    public:
        long produce();
        long consume();

        thread_object()
        {
            pthread_mutex_init(&obj_lock1, NULL);
            pthread_mutex_init(&obj_lock2, NULL);
            num_elements1 = 0;
            num_elements2 = 0;
            num_elements_consumed = 0;
            elements1 = (int *)malloc(2 * 1024 * 1024);
            elements2 = (int *)malloc(2 * 1024 * 1024);
            next = 0;
        }

        bool lock()
        {
            bool id = next;
            pthread_mutex_t* obj = (id) ? (&obj_lock2) : (&obj_lock1);
            if (pthread_mutex_trylock(obj) != 0)
            {
                id = !id;
                obj = (id) ? (&obj_lock2) : (&obj_lock1);
                pthread_mutex_lock(obj);
            }

            next = !id;
            return id;
        }

        void lock(bool lockid)
        {
            pthread_mutex_t* obj = (lockid) ? (&obj_lock2) : (&obj_lock1);
            pthread_mutex_lock(obj);
            next = !lockid;
        }

        void unlock(bool id)
        {
            pthread_mutex_t* obj = (id) ? &obj_lock2 : &obj_lock1;

            pthread_mutex_unlock(obj);
        }

        inline int elements_consumed()
        {
            return num_elements_consumed;
        }

        void clear()
        {
            num_elements1 = 0;
            num_elements2 = 0;
            num_elements_consumed = 0;
        }

    private:
        int num_elements_consumed;
        pthread_mutex_t obj_lock1;
        pthread_mutex_t obj_lock2;

        // these are the elements which will be produced and consumed
        int *elements1;
        int *elements2;
        // the number of elements at present ready to be consumed
        int num_elements1;
        int num_elements2;
        bool next;
};

long thread_object::produce()
{
    int lockid = lock();

    if (lockid == -1)
        return 0;
    //printf("producer locks %d\n", lockid); 
    int& num_elements = (lockid) ? num_elements2 : num_elements1;
    int* elements = (lockid) ? elements2 : elements1;

    long i = 0;
    long num_elements_produced = 0;
    if (num_elements == MAX_ELEMENTS)
    {
        goto end;
    }

    if (num_elements > MAX_ELEMENTS)
    {
        cout << endl << num_elements << endl;
        assert(0);
    }


    // produce elements
    for (i = num_elements; i < num_elements + BATCH_SIZE; i++)
    {
        if (i == MAX_ELEMENTS)
            break;

        elements[i] = 1;
    }

    num_elements_produced = i - num_elements;
    num_elements = i;

end:
    unlock(lockid);
    return num_elements_produced;
}

long thread_object::consume()
{
    int lockid = lock();
    //printf("consumer locks %d of tid %d\n", lockid, omp_get_thread_num());
    int& num_elements = (lockid) ? num_elements2 : num_elements1;
    int* elements = (lockid) ? elements2 : elements1;
    assert(num_elements >= 0);

    long i = 0;

    // no elements to consume
    if (num_elements == 0)
    {
        unlock(lockid);
        //printf("\tconsumer unlocks %d of tid %d", lockid, omp_get_thread_num());
        lockid = !lockid;
        lock(lockid);
        //printf("consumer locks %d of tid %d\n", lockid, omp_get_thread_num());
        num_elements = (lockid) ? num_elements2 : num_elements1;
        elements = (lockid) ? elements2 : elements1;
        if (num_elements == 0)
            goto end;
    }


    // there are elements we can consume
    // consume
    for (i = 0; i < BATCH_SIZE; i++)
    {
        num_elements_consumed += elements[--num_elements];

        if (num_elements == 0)
            break;
    }

end:

    unlock(lockid);
    //printf("consumed %ld\n", i);
    return i;
}

thread_object objects[MAX_THREADS];
bool producing_done = false;

void *producer(void *arg)
{
    kmp_affinity_mask_t mask;
    kmp_create_affinity_mask(&mask);
    if (kmp_set_affinity_mask_proc(0, &mask) != 0)
    {
        exit(1);
    }
    long num_elements_to_produce = ACCESSES;

    int num_consumers = omp_get_max_threads();
    long elements_produced = 0;
    int iter = 0;
    while (elements_produced < num_elements_to_produce)
    {
        iter++;
        for (int i = 0; i < num_consumers; i++)
        {
            elements_produced += objects[i].produce();
        }
        //printf("produced %ld\n", elements_produced);
    }

    kmp_destroy_affinity_mask(&mask);
    producing_done = true;
    printf("producer thread exiting, iter %d\n", iter); 
    return NULL;
}

void consumer(long num_elements_to_consume)
{
    int num_consumers = omp_get_max_threads();
    printf("each thread will consumer %ld\n", num_elements_to_consume);

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < num_consumers; i++)
    {
        int tid = omp_get_thread_num();
        //printf("thread id %d\n", tid);
        kmp_affinity_mask_t mask;
        kmp_create_affinity_mask(&mask);
        if (kmp_set_affinity_mask_proc(tid+1, &mask) != 0)
        {
            exit(1);
        }

        while(1)
        {
            int tid = omp_get_thread_num();

            if (objects[tid].consume() == 0)
            {
                // no more production, so you can exit
                if (producing_done == true)
                    break;
            }

            // maximum elements consumed
            if (objects[tid].elements_consumed() >= num_elements_to_consume)
                break;
        }
        kmp_destroy_affinity_mask(&mask);
        printf("\nconsumer thread exiting with tid %d, consumed %d\n", tid, objects[tid].elements_consumed());
    }

}

int main(int argc, char** argv)
{
    pthread_t tp;
    int num_times = 1;
    float time_seq = 1, time_par = 0;
    int max_threads = omp_get_max_threads();
    cerr << "Max threads " << max_threads << endl;

    #pragma omp parallel num_threads(1)
    {
        int test = 0;
    }
    // start producer consumer
    for (BATCH_SIZE=512; BATCH_SIZE <= 512; BATCH_SIZE *=2)
    {
        cout << endl << BATCH_SIZE * sizeof(int) << ", " ;

        for(int num_threads = 1; num_threads < max_threads; num_threads++)
        {
            struct timeval before, after;
            omp_set_num_threads(num_threads);
            time_par = 0;

            for (int i = 0; i < num_times; i++)
            {
                recordTime(before);

                pthread_create(&tp, NULL, producer, NULL);
                consumer(ACCESSES/(num_threads));
                pthread_join(tp, NULL);

                recordTime(after);

                time_par += diffTime(before, after, "");

                // clear for next run
                for (int i = 0; i < MAX_THREADS; i++)
                    objects[i].clear();

                producing_done = false;

            }
            // avg value
            time_par = time_par / num_times;
            if (num_threads == 1)
            {
                time_seq = time_par;
                cout << time_seq << ", ";
            }

            cout << time_seq / time_par  << ", ";
        }
    }

    cout << endl;

    return 0;
}
