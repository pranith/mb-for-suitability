#include <stdio.h>
#include <stdlib.h>

int *src;

int main(int argc, char* argv[])
{
  unsigned long size = 256 * 1024 * 1024 / sizeof(int); // 256 MB
  src = (int *)malloc(sizeof(int) * size);
  unsigned long i = 0, j, k;
  volatile register int dest1, dest2, dest3, dest4, dest5, dest6;
  int ai = 5;
  int num_mem_ops = 6;

  unsigned long num_iter = 1000000000 / num_mem_ops;
  int inc = 16 * num_mem_ops;
  int num_ops = ai * num_mem_ops;
  for(j = 0; j < num_iter; j++)
  {
    src[i] = dest1;
    src[i+16] = dest2;
    src[i+32] = dest3;
    src[i+48] = dest4;
    src[i+64] = dest5;
    src[i+80] = dest6;
    /*
    */

    // ARITHMETIC INTENSITY
    for (k = 0; k < num_ops; k++)
      dest6 += 1;

    i+=inc;
    if (i+(inc - 16) >= size)
      i = 0;
  }

  return 0;
}
