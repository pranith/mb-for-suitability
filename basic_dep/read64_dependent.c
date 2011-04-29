/* Here we are reading from contigous cache lines to the same destination
 * this is a dependent read i.e., a previous read must complete before next read
 */

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

long *src;
long result;

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

int main(int argc, char* argv[])
{
  unsigned long size = 256 * 1024 * 1024 / sizeof(long); // 256 MB
  src = (long *)malloc(sizeof(long) * size);
  unsigned long i = 0, j;
  //volatile long dest1, dest2, dest3, dest4, dest5, dest6, dest7, dest8;
  int num_mem_ops = 8;

  unsigned long num_iter = 5000000000 / num_mem_ops;
  struct timeval before, after;

  //initialize array
  for (j = 0; j < size; j++)
    src[j] = 8;

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

    if (i >= size)
      i = 0;
  }
  recordTime(&after);

  result = i;

  printf("time taken %f\n", diffTime(before, after));
  return 0;
}
