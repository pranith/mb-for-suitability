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
    src[j] = 8;

  int inc = 1;
  recordTime(&before);
  for(j = 0; j < num_iter; j++)
  {
    l = i;
    #pragma unroll
    for (k = 0; k < 400; k++)
    {
      dest += src[l];
      l += inc;
    }

    /* make subsequent iterations dependent on previous iterations */
    i += dest;
    dest = 0;

    if (i+max >= size)
      i = 0;
  }
  recordTime(&after);

  result = i + dest;

  printf("num req %d time taken %f\n", num_req, diffTime(before, after));
  return 0;
}
