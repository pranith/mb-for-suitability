/* 
 * memory is being shared by all 4 threads
 *
 * both shared and non shared accesses
 * both shared and non shared memory
 */

#include <omp.h>
#include "bench.h"
#include <assert.h>

#include <string.h>

//#define ACCESSES 1000
#define AI 0

void stride(int* dest, int* src, int startindex, int endindex, long num_accesses, int64_t block_size, int shared_acc_percent, int shared_mem_percent)
{
    int array_len = endindex - startindex + 1;
    int shared_len = (array_len * shared_mem_percent) / 100;
    int block_len = block_size / sizeof(int);

    // we have unshared accesses followed by shared accesses
    long num_accesses_shared = (num_accesses * shared_acc_percent) / 100 ;
    long num_accesses_unshared = num_accesses - num_accesses_shared;

    int sum = 0;
    int index = startindex;
    int local[block_len];

    // unshared accesses
    for (long i = 0; i < num_accesses_unshared; i++)
    {
        memcpy(local, src+index, block_size);

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

        if (index > shared_len)
            index = 0;

        sum += local[0];
    }

    finaldest[omp_get_thread_num()] = sum;
    return;
}
