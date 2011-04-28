#include <stdio.h>
#include <stdlib.h>

int *src;

int main()
{
  unsigned size = 256 * 1024 * 1024 / sizeof(int); // 256 MB
  src = (int *)malloc(sizeof(int) * size);
  unsigned i = 0, j, k;
  volatile register int dest;

  int num_reads = 4;
  unsigned long num_iter = 1000000000 / 3;
  for(j = 0; j < num_iter; j++)
  {
    #pragma unroll
    for (k = 0; k < 10; k++)
    {
        dest = src[k];
    }

    if (i+3 >= size)
      i = 0;
  }

  return 0;
}
