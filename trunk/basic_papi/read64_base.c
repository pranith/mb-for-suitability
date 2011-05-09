/* reading from the same location to different destination locations
 */


#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

long *src;
int *indexarr;
long result;
unsigned long size;
int num_req = 0;

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
  indexarr = (int *)malloc(sizeof(int) * 400);

  for (j = 0; j < 400; j++)
  {
    indexarr[j] = (num_req * j) / 50;
  }

  //initialize array
  for (j = 0; j < size; j++)
    src[j] = 3200;
}

int test()
{
  unsigned long i = 0, j;
  int num_mem_ops = 400;

  volatile unsigned long dest;
  unsigned long num_iter = 200000000000 / num_mem_ops;
  struct timeval before, after;

  recordTime(&before);
  for(j = 0; j < num_iter; j++)
  {
    dest = src[i + indexarr[0]];

    i += dest;
    if (i+3200 >= size)
      i = 0;
  }
  recordTime(&after);

  result += i;

  printf("time taken %f\n", diffTime(before, after));
  printf("Num iter %d M\n", (int) (num_iter / 1000000));
  return 0;
}

