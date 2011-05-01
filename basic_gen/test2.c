#define REPEAT400(b) \
    REPEAT200(b);\
    REPEAT200(b)\

#define REPEAT200(b) \
    REPEAT100(b);\
    REPEAT100(b)\

#define REPEAT100(b) \
    REPEAT50(b);\
    REPEAT50(b)\

#define REPEAT50(b) \
    REPEAT25(b);\
    REPEAT25(b)\

#define REPEAT25(b) \
    REPEAT5(b);\
    REPEAT5(b);\
    REPEAT5(b);\
    REPEAT5(b);\
    REPEAT5(b)\

#define REPEAT5(b) \
  b;\
  b;\
  b;\
  b;\
  b\

int final;

int main()
{
  int src[100], dest;

#pragma unroll
  REPEAT400(dest = src[i]);

  final = dest;

  return final;
}
