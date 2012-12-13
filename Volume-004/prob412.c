#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50

static int nums[MAX_N];

int gcd(int a, int b)
{
  int temp;

  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }

  return abs(a);
}

int main()
{
  int n;

  while (scanf("%d", &n) && n > 0) {
    int i, count = 0;

    for (i = 0; i < n; ++i) {
      int j;

      scanf("%d", nums + i);

      for (j = 0; j < i; ++j) {
        if (gcd(nums[i], nums[j]) == 1) ++count;
      }
    }

    if (count == 0)
      printf("No estimate for this data set.\n");
    else
      printf("%.6lf\n", sqrt(6.0 * n * (n - 1) / (2 * count)));
  }

  return 0;
}
