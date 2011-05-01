/* reading from the same location to different destination locations
 */


#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

long *src;
long result;
unsigned long size;

void recordTime(struct timeval* current)
{
    gettimeofday(current, NULL);

    return;
}

float diffTime(struct timeval before, struct timeval after)
{
    float time_sec = ((after.tv_sec - before.tv_sec) + ((after.tv_usec - before.tv_usec) / 1000000.0));

    return time_sec;
}

void warmup()
{
  unsigned long j = 0;
  size = 256 * 1024 * 1024 / sizeof(long); // 256 MB
  src = (long *)malloc(sizeof(long) * size);

  //initialize array
  for (j = 0; j < size; j++)
    src[j] = 1;
}

int test()
{
  unsigned long i = 0, j;
  int num_mem_ops = 8;

  unsigned long num_iter = 5000000000 / num_mem_ops;
  struct timeval before, after;

  recordTime(&before);
  for(j = 0; j < num_iter; j++)
  {
    i += src[i];
    i += src[i];
    i += src[i];
    i += src[i];
    i += src[i];
    i += src[i];
    i += src[i];
    i += src[i];

    if (i >= 8)
      i = 0;
  }
  recordTime(&after);

  result = i;

  printf("time taken %f\n", diffTime(before, after));
  return 0;
}


