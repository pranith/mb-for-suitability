#ifndef _MAIN_
#define _MAIN_

#include "portability.h"

#define ACCESSES 10000000000
#define MAX_THREADS 8
#define CACHE_LINE_SIZE 64

int finaldest[MAX_THREADS];

void recordTime(struct timeval& current)
{
    gettimeofday(&current, NULL);

    return;
}

float diffTime(struct timeval before, struct timeval after, string loc)
{
    float time_sec = ((after.tv_sec - before.tv_sec) + ((after.tv_usec - before.tv_usec) / 1000000.0));

    //cout << loc << " : Time Taken " << time_sec << " sec" << endl;
    //cerr << loc << " : Time Taken " << time_sec << " sec" << endl;

    return time_sec;
}

void testfinal()
{
    return;
    for (int i = 0; i < MAX_THREADS; i++)
        cout << "finaldest[" << i << "] " << finaldest[i] << endl;
}

#endif // _MAIN_
