#include <stdio.h>
#include <stdlib.h>

int *src;

int main(int argc, char* argv[])
{
  unsigned long size = 256 * 1024 * 1024 / sizeof(int); // 256 MB
  src = (int *)malloc(sizeof(int) * size);
  unsigned long i = 0, j, k;
  volatile register int dest, temp;
  int ai = 10;
  int num_mem_ops = 1;

  unsigned long num_iter = 10000000000 / num_mem_ops;
  int inc = 16 * num_mem_ops;
  int num_ops = ai * num_mem_ops;
  for(j = 0; j < num_iter; j++)
  {
    dest = src[i];
    /*
    dest = src[i+16];
    dest = src[i+32];
    dest = src[i+48];
    dest = src[i+64];
    dest = src[i+80];
    */

    // ARITHMETIC INTENSITY
    for (k = 0; k < num_ops; k++)
      temp += 1;

    i=+inc;
    if (i+(inc - 16) >= size)
      i = 0;
  }

  return 0;
}
