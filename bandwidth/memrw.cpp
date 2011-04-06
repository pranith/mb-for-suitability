/* memset.cpp
 *
 * try to maximize bandwidth by bombarding with memsets
 */

#include <omp.h>
#include "bench.h"
#include <assert.h>

#include <string.h>

#define ACCESSES 1000000
#define AI 0

void stride(int* dest, int* src, int startindex, int endindex, long num_accesses, int64_t block_size)
{
    //printf("In thread %d, startindex %d, endindex %d, num_accesses %ld\n", omp_get_thread_num(), startindex, endindex, num_accesses);
    int sum = 0;
    int num_ops = (endindex - startindex + 1) * sizeof(int) * AI;
    int index = startindex;
    int block_len = block_size / sizeof(int);

    int local[block_len];
    bool mode = 0;

    for (long i = 0; i < num_accesses; i++)
    {
        // copy the block of memory
        if (mode)
        {
            memcpy(local, src + index, block_size);
            sum += local[0];
        }
        else
        {
            memcpy(src+index, local, block_size);
            sum += src[index];
        }

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

        mode = !mode;
    }
    finaldest[omp_get_thread_num()] = sum;

    return;
}
