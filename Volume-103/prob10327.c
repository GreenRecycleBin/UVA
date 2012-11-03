#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000

int main()
{
  int a[MAX_N], n;

  while (scanf("%d", &n) == 1) {
    int i, count = 0;
    bool did_swap;

    for (i = 0; i < n; ++i) scanf("%d", a + i);

    do {
      did_swap = false;

      for (i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
          int temp = a[i];
          a[i] = a[i + 1];
          a[i + 1] = temp;
          ++count;
          did_swap = true;
        }
      }
    } while (did_swap);

    printf("Minimum exchange operations : %d\n", count);
  }

  return 0;
}
