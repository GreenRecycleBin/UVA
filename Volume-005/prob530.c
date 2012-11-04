#include <stdio.h>

int main()
{
  int n, k;

  while (scanf("%d %d", &n, &k) == 2 && (n > 0 || k > 0)) {
    long long r = 1, i;

    if (k > n / 2) k = n - k;

    for (i = 1; i <= k; ++i) {
      r *= n + 1 - i;
      r /= i;
    }

    printf("%d\n", (int)r);
  }

  return 0;
}
