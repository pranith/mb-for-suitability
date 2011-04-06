/* 
 * memory is being shared by all 4 threads
 *
 * access pattern is such that the shared data is mostly accessed simulatenously
 * i.e., contention for the same data is very high
 * 
 * only reads in this mb
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
    int array_len = endindex - startindex + 1;
    int block_len = block_size / sizeof(int);
    int local[block_len];

    // we have unshared accesses followed by shared accesses
    int shared_array_len = (array_len * SHARED_PERCENT) / 100;
    long num_accesses_shared = (num_accesses * SHARED_PERCENT) / 100 ;
    long num_accesses_unshared = num_accesses - num_accesses_shared;

    int sum = 0;
    int index = startindex;

    // unshared accesses
    for (long i = 0; i < num_accesses_unshared; i++)
    {
        memcpy(local, src+index, block_len);

        index += block_len;
        if (index > endindex)
            index = startindex;

        sum += local[0];
    }

    // shared accesses
    index = 0;
    for (long i = 0; i < num_accesses_shared; i++)
    {
        memcpy(dest+index, local, block_size);

        index += block_len;

        if (index > shared_array_len)
            index = 0;

        sum += local[0];
    }

    finaldest[omp_get_thread_num()] = sum;
    return;
}
