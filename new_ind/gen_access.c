#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i = 0;
  for (i = 0; i < 400; i++)
    printf("dest = src[i + indexarr%d];\n", i);

  return 0;
}
