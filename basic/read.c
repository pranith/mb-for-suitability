#include <stdio.h>
#include <stdlib.h>

long *src;

int main(int argc, char* argv[])
{
  unsigned long size = 256 * 1024 * 1024 / sizeof(long); // 256 MB
  src = (long *)malloc(sizeof(long) * size);
  printf("size of long %d\n", sizeof(long));
  unsigned long i = 0, j, k;
  volatile long dest1, dest2, dest3, dest4, dest5, dest6, dest7, dest8;
  int num_mem_ops = 8;

  unsigned long num_iter = 1000000000 / num_mem_ops;
  int inc = 16 * num_mem_ops;
  for(j = 0; j < num_iter; j++)
  {
    dest1 += src[i];
    dest2 += src[i];
    dest3 += src[i];
    dest4 += src[i];
    dest5 += src[i];
    dest6 += src[i];
    dest7 += src[i];
    dest8 += src[i];

    i+=inc;
    if (i+(inc - 16) >= size)
      i = 0;
  }

  return 0;
}
