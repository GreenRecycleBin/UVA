#include <stdio.h>

int main()
{
  int n;

  while (scanf("%d", &n) == 1) {
    int remainder = 1 % n, count = 1;

    while (remainder > 0) {
      remainder = remainder * 10 + 1;
      remainder %= n;
      ++count;
    }

    printf("%d\n", count);
  }

  return 0;
}
