#include <stdio.h>
#include <stdlib.h>

int *src;

int main(int argc, char* argv[])
{
  unsigned long size = 256 * 1024 * 1024 / sizeof(int); // 256 MB
  src = (int *)malloc(sizeof(int) * size);
  unsigned long i = 0, j;
  volatile register int dest;

  unsigned long num_iter = 10000000000 / 5;
  for(j = 0; j < num_iter; j++)
  {
    dest = src[i];
    dest = src[i+16];
    dest = src[i+32];
    dest = src[i+48];
    dest = src[i+64];

    i=+80;
    if (i+80 >= size)
      i = 0;
  }

  return 0;
}
