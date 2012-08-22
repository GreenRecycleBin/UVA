#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 3650

static bool has_strike[MAX_N];

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int n, p, h, count, i;
    scanf("%d %d", &n, &p);

    memset(has_strike, 0, sizeof(bool) * n);

    for (i = 0; i < p; ++i) {
      scanf("%d", &h);

      int j;

      for (j = h - 1; j < n; j += h) has_strike[j] = true;
    }

    for (count = 0, i = 0; i < n; ++i) {
      if (has_strike[i] && i % 7 != 5 && i % 7 != 6) {
        ++count;
      }
    }

    printf("%d\n", count);
  }

  return 0;
}
