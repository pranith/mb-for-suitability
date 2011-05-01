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
  size = 256 * 1024 * 1024 / sizeof(long); // 256 MB
  src = (long *)malloc(sizeof(long) * size);
}

int test()
{
  unsigned long i = 0, j;
  volatile long dest1, dest2, dest3, dest4, dest5, dest6, dest7, dest8;
  int num_mem_ops = 8;

  unsigned long num_iter = 5000000000 / num_mem_ops;
  struct timeval before, after;

  //initialize array
  for (j = 0; j < size; j++)
    src[j] = 8;

  recordTime(&before);
  for(j = 0; j < num_iter; j++)
  {
    dest1 = src[i];
    dest2 = src[i+8];
    dest3 = src[i+16];
    dest4 = src[i+24];
    dest5 = src[i+32];
    dest6 = src[i+40];
    dest7 = src[i+48];
    dest8 = src[i+56];

    /* make subsequent iterations dependent on previous iterations */
    i += (dest1 + dest2 + dest3 + dest4 + dest5 + dest6 + dest7 + dest8);

    if (i+56 >= size)
      i = 0;
  }
  recordTime(&after);

  result = i + dest1 + dest2 + dest3 + dest4 + dest5 + dest6 + dest7 + dest8;

  printf("time taken %f\n", diffTime(before, after));
  return 0;
}
