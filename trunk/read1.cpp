/* 
 * memory is being shared 
 *
 * both the threads only READ from the same shared memory location in this mb
 */

#include <omp.h>
#include "bench.h"
#include <assert.h>

#include <string.h>

//#define ACCESSES 1000
#define AI 0
#define SHARED_PERCENT 10

void stride(int* dest, int* src, int startindex, int endindex, long num_accesses, int64_t block_size, bool base)
{
    int num_threads = omp_get_num_threads();
    int tid = omp_get_thread_num();

    int array_len = endindex - startindex + 1;
    int shared_len = (array_len * SHARED_PERCENT) / (num_threads * 100);
    int block_len = block_size / sizeof(int);

    // even threads increase the array towards the end
    // odd threads increase the array towards the beginning
    // even and odd threads share this increased part
    if (tid % 2 != 0)
        startindex -= shared_len;
    else if (num_threads != 1)
        endindex += shared_len;

    int sum = 0;

    int local[block_len];
    int index = startindex;
    for (long i = 0; i < num_accesses; i++)
    {
        // read from the shared memory
        memcpy(local, dest, block_size);

        index += block_len; 
        if (index > endindex)
            index = startindex;

        sum += local[0];
    }

    finaldest[omp_get_thread_num()] = sum;
    return;
}
