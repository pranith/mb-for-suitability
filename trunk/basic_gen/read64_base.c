/* reading from the same location to different destination locations
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
  unsigned long i = 0, j, k = 0, l;
  volatile long dest;
  int num_mem_ops = 8;

  unsigned long num_iter = 5000000000 / num_mem_ops;
  struct timeval before, after;

  //initialize array
  for (j = 0; j < size; j++)
    src[j] = 1;

  int inc = 1;
  int max = inc * 400;
  recordTime(&before);
  for(j = 0; j < num_iter; j++)
  {
    l = i;
    #pragma unroll
    for (k = l; k < 4; k++)
    {
      dest += src[k];
    }

    /* make subsequent iterations dependent on previous iterations */
    i += (dest * inc);
    dest = 0;

    if (i+max >= size)
      i = 0;
  }
  recordTime(&after);

  result = i + dest;

  printf("num req %d time taken %f\n", 400 / (8 * inc), diffTime(before, after));
  return 0;
}
