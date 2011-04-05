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

#include "main.h"

using namespace std;

float Par(int64_t len, int64_t block_size, bool base);
float Seq(int64_t len, int64_t block_size, bool base);
void stride(int* dest, int* src, int startindex, int endindex, long num_accesses, int64_t block_size, bool base);

bool test = 0;

int main(int argc, char** argv)
{
    int64_t start_len = 1024 * 1024 * 2 / sizeof(int); // 2 MB
    int64_t dobase = 0;
    int block_size = CACHE_LINE_SIZE;
    int max_threads = omp_get_max_threads();
    cout << "max_threads : " << max_threads << endl;
    int max_array_len = 1024 * 1024 * 1024 / sizeof(int); // 1024 MB
    int max_block_size = 512 / sizeof(int);

    int64_t len = start_len; // length of the array
    if (argc == 3)
    {
        len     = atoll  (argv[1]);
        dobase   = atoll  (argv[2]);
    }
    else if (argc == 2)
        dobase = atoll (argv[1]);

    if (test)
    {
        start_len = max_array_len  / 2; 
        block_size = max_block_size / 2; // 64B
    }
    assert(len     > 0);
    assert(dobase  == 0 ||
            dobase == 1);

    if (dobase == 1)
    {
        float time_seq_base = Seq(len, block_size, dobase);
        float time_par_base = Par(len, block_size, dobase);
        cout << "Speedup : " << time_seq_base / time_par_base << endl;
    }

    for (; block_size < max_block_size; block_size *= 2)
    {
        cout << " size(MB),time(seq),num_threads=2; block_size="<< block_size \
            << ",num_threads=4; block_size="<< block_size << endl;
        for (len = start_len; len < max_array_len; len *= 2)
        {
            cout << (len * sizeof(int)) / (1024 * 1024); // printing size in MB
            float time_seq = Seq(len, block_size, 0);
            cout << ", " << time_seq;
            for (int num_threads = 2; num_threads <= max_threads; num_threads *= 2)
            {
                omp_set_num_threads(num_threads);
                float time_par = Par(len, block_size, 0);
                cout << ", " << time_seq / time_par;
            }
            cout << endl;
        }
    }


    return 0;
}

float Par(int64_t len, int64_t block_size, bool base) 
{
    int* src   = (int*)malloc(sizeof(int) * len);
    int* dest   = (int*)malloc(sizeof(int) * len);

    struct timeval before, after;

    recordTime(before);
    #pragma omp parallel for schedule(static)
    for (int64_t acc   = 0; acc < omp_get_num_threads(); acc++) 
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int startindex = tid * len / num_threads;
        int endindex = ((tid + 1) * len / num_threads) - 1;
        stride(dest, src, startindex, endindex, ACCESSES / num_threads, block_size, base);
    }
    recordTime(after);

    testfinal();
    free(src);
    free(dest);
    return diffTime(before, after, "Par");
}

float Seq(int64_t len, int64_t block_size, bool base) 
{
    int* src   = (int*)malloc(sizeof(int) * len);
    int* dest   = (int*)malloc(sizeof(int) * len);

    struct timeval before, after;

    recordTime(before);
    for (int64_t acc   = 0; acc < omp_get_num_threads(); acc++) 
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int startindex = tid * len / num_threads;
        int endindex = ((tid + 1) * len / num_threads) - 1;
        stride(dest, src, startindex, endindex, ACCESSES / num_threads, block_size, base);
    }
    recordTime(after);

    testfinal();
    free(src);
    free(dest);
    return diffTime(before, after, "Seq");
}
