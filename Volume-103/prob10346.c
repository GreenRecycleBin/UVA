#include <stdio.h>

int main()
{
  int n, k;

  while (scanf("%d %d", &n, &k) != EOF) {
    int total = n, current = n, extra = current / k, rest;

    while (extra > 0) {
      rest = current % k;
      total += extra;
      current = extra + rest;
      extra = current / k;
    }

    printf("%d\n", total);
  }

  return 0;
}
