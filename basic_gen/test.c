int final;

int main()
{
  int src[100], dest, j = 0;

  #pragma unroll
  for(j = 0; j <= 4; j++)
    dest = src[j];

  final = dest;

  return final;
}
