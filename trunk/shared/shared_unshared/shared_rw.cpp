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

void stride(int* dest, int* src, int startindex, int endindex, long num_accesses, int64_t block_size, int shared_acc_percent, int shared_mem_percent)
{
    int array_len = endindex - startindex + 1;
    int block_len = block_size / sizeof(int);
    int local[block_len];

    // we have unshared accesses followed by shared accesses
    int shared_array_len = (array_len * shared_mem_percent) / 100;
    long num_accesses_shared = (num_accesses * shared_acc_percent) / 100 ;
    long num_accesses_unshared = num_accesses - num_accesses_shared;

    int sum = 0;
    int index = startindex;

    // unshared accesses
    for (long i = 0; i < num_accesses_unshared; i++)
    {
        memcpy(local, src+index, block_len);

        index += block_len;
        if (index > (endindex - block_len))
            index = startindex;

        sum += local[0];
    }

    // shared accesses
    int shared_index = 0;
    bool mode = 0;
    for (long i = 0; i < num_accesses_shared; i++)
    {
        if (mode)
        {
            memcpy(dest+shared_index, local, block_size);
            sum += dest[shared_index];
        }
        else
        {
            memcpy(local, dest+shared_index, block_size);
            sum += local[0];
        }

        shared_index += block_len;
        if (shared_index > (shared_array_len - block_len))
            shared_index = 0;

        mode = !mode;
    }

    finaldest[omp_get_thread_num()] = sum;
    return;
}
