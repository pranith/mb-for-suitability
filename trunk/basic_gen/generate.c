int main()
{
  int i = 0;
  printf("int \\ \n");
  for (i = 0; i < 400; i++)
    printf(" dest%d,\\ \n", i);
  for (i = 0; i < 400; i++)
    printf("dest%d = src[i + ((num_req * %d) / 50)];\n",i, i);
  printf("result = 1 \\ \n");
  for (i = 0; i < 400; i++)
    printf(" + dest%d,\\ \n", i);
}
