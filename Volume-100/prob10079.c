#include <stdio.h>

int main()
{
  int n;

  while (scanf("%d", &n) != EOF && n >= 0) {
    printf("%ld\n", ((long)n * n + n + 2) / 2);
  }

  return 0;
}
