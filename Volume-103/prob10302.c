#include <math.h>
#include <stdio.h>

#define MAX_N 50000

int main()
{
  unsigned long long cache[MAX_N];
  int i;
  cache[0] = 1;

  for (i = 1; i < MAX_N; ++i) cache[i] = cache[i - 1] + (unsigned long long)(i + 1) * (i + 1) * (i + 1);

  while (scanf("%d", &i) == 1) printf("%llu\n", cache[i - 1]);

  return 0;
}
