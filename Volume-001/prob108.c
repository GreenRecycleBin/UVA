#include <stdio.h>

static int nums[101][101];

int main()
{
  int n, i, j, k, max;
  scanf("%d", &n);

  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      scanf("%d", &nums[i][j]);
      nums[i][j] += nums[i - 1][j];
    }
  }

  max = nums[1][1];

  for (i = 0; i < n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      int temp = 0;
      for (k = 1; k <= n; ++k) {
	temp += nums[j][k] - nums[i][k];

	if (temp < 0) temp = 0;
	if (temp > max) max = temp;
      }
    }
  }

  printf("%d\n", max);

  return 0;
}
