#include <math.h>
#include <stdio.h>

int main()
{
  int n;

  while (scanf("%d", &n) == 1 && n > 0) {
    int k = ceil(sqrt(n)), top_right = k * (k - 1) + 1, x, y;

    if (k % 2 == 0) {
      if (n < top_right) {
        x = k;
        y = k - (top_right - n);
      }
      else {
        x = k - (n - top_right);
        y = k;
      }
    }
    else {
      if (n < top_right) {
        x = k - (top_right - n);
        y = k;
      }
      else {
        x = k;
        y = k - (n - top_right);
      }
    }

    printf("%d %d\n", y, x);
  }

  return 0;
}
