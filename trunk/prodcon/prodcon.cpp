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

#define MAX_ELEMENTS 1024
// batch size is equal to a cache block size
int BATCH_SIZE=16;
#undef ACCESSES
#define ACCESSES 1000000000
//#define ACCESSES 10000

using namespace std;

class thread_object
{
    public:
        long produce();
        long consume();

        thread_object()
        {
            pthread_mutex_init(&obj_lock, NULL);
            num_elements = 0;
            num_elements_consumed = 0;
        }

        void lock()
        {
            pthread_mutex_lock(&obj_lock);
        }

        void unlock()
        {
            pthread_mutex_unlock(&obj_lock);
        }

        inline int elements_consumed()
        {
            return num_elements_consumed;
        }

        void clear()
        {
            num_elements = 0;
            num_elements_consumed = 0;
        }

    private:
        int num_elements_consumed;
        pthread_mutex_t obj_lock;

        // these are the elements which will be produced and consumed
        int elements[MAX_ELEMENTS];
        // the number of elements at present ready to be consumed
        int num_elements;
};

long thread_object::produce()
{
    if (num_elements == MAX_ELEMENTS)
        return 0;

    if (num_elements > MAX_ELEMENTS)
    {
        cout << endl << num_elements << endl;
        assert(0);
    }

    int i = 0;

    lock();

    // produce elements
    for (i = num_elements; i < num_elements + BATCH_SIZE; i++)
    {
        if (i == MAX_ELEMENTS)
            break;

        elements[i] = 1;
    }

    long num_elements_produced = i - num_elements;
    num_elements = i;

    unlock();

    return num_elements_produced;
}

long thread_object::consume()
{
    assert(num_elements >= 0);

    // no elements to consume
    if (num_elements == 0)
    {
        //cout << "thread starving " << omp_get_thread_num() << "consumed " << elements_consumed() << endl;
        return 0;
    }

    int i = 0;

    // there are elements we can consume
    // consume
    lock();
    for (i = 0; i < BATCH_SIZE; i++)
    {
        num_elements_consumed += elements[--num_elements];

        if (num_elements == 0)
            break;
    }

    unlock();

    return i;
}

thread_object objects[MAX_THREADS];
bool producing_done = false;

void *producer(void *arg)
{
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
    }

    producing_done = true;
    //cout << "producer thread exiting " << iter << endl;
    return NULL;
}

void consumer(long num_elements_to_consume)
{
    int num_consumers = omp_get_max_threads();
    //cout << num_elements_to_consume << endl;

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < num_consumers; i++)
    {
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
    }

}

int main(int argc, char** argv)
{
    pthread_t tp;
    float time_seq = 1, time_par;
    int max_threads = omp_get_max_threads();
    cerr << "Max threads " << max_threads << endl;
    // start producer consumer
    for (BATCH_SIZE=4; BATCH_SIZE <= 128; BATCH_SIZE *=2)
    {
        cout << endl << BATCH_SIZE * sizeof(int) << ", " ;
        for(int num_threads = 1; num_threads < max_threads; num_threads++)
        {
            struct timeval before, after;
            omp_set_num_threads(num_threads);

            recordTime(before);
            pthread_create(&tp, NULL, producer, NULL);
            consumer(ACCESSES/(num_threads));
            pthread_join(tp, NULL);
            recordTime(after);

            time_par = diffTime(before, after, "");

            if (num_threads == 1)
            {
                time_seq = time_par;
                cout << time_seq << ", ";
            }

            cout << time_par / time_seq  << ", ";

            for (int i = 0; i < MAX_THREADS; i++)
                objects[i].clear();

            producing_done = false;

            sleep(3);
        }
    }

    cout << endl;

    return 0;
}
