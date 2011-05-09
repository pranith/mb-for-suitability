#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i = 0, num_req = 1;
  unsigned long j = 0;
  int *indexarr = (int *)malloc(sizeof(int) * 400);

  if (argc > 1)
    num_req = atoi(argv[1]);
  for (j = 0; j < 400; j++)
  {
    indexarr[j] = (num_req * j * 32) / 400;
  }
  for (i = 0; i < 400; i++)
    printf("#define indexarr[%d] %d\n", i, indexarr[i]);

  return 0;
}
