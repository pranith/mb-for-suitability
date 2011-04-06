/* memwrite.cpp
 *
 * try to maximize bandwidth by bombarding with memcpy
 *
 * write to a range of shared memory
 */

#include <omp.h>
#include "bench.h"
#include <assert.h>

#include <string.h>

#define ACCESSES 1000000
#define AI 0

void stride(int* dest, int* src, int startindex, int endindex, long num_accesses, int64_t block_len)
{
    //printf("In thread %d, startindex %d, endindex %d, num_accesses %ld\n", omp_get_thread_num(), startindex, endindex, num_accesses);
    int sum = 0;
    int num_ops = (endindex - startindex + 1) * sizeof(int) * AI;
    int index = startindex;
    int block_size = block_len * sizeof(int);

    int local[block_len];

    for (long i = 0; i < num_accesses; i++)
    {
        // copy the block of memory
        memcpy(src + index, local, block_size);

        sum += src[index];

        int ai_index = index;
        for (long j = 0; j < num_ops; j++)
        {
            ai_index++;
            sum += local[ai_index];

            // work only on the block of memory copied
            if (ai_index > (index + block_len))
                ai_index = index;
        }
        //assert(index <= endindex && startindex <= index);

        index += block_len;
        if (index > endindex - block_len)
            index = startindex;
    }
    finaldest[omp_get_thread_num()] = sum;

    return;
}
