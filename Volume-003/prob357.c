#include <stdio.h>

#define MAX_N 30000
#define NUM_DENOMINATORS 5

static int denominators[NUM_DENOMINATORS + 1] = {0, 1, 5, 10, 25, 50};
static long matrix[NUM_DENOMINATORS + 1][MAX_N + 1];

long GetNumberOfWaysToMakeChange(int n)
{
  int i;

  for (i = 1; i <= n; ++i) matrix[0][i] = 0;
  for (i = 0; i <= NUM_DENOMINATORS; ++i) matrix[i][0] = 1;

  for (i = 1; i <= NUM_DENOMINATORS; ++i) {
    int j;

    for (j = 1; j <= n; ++j) {
      if (denominators[i] > j)
        matrix[i][j] = matrix[i - 1][j];
      else
        matrix[i][j] = matrix[i - 1][j] + matrix[i][j - denominators[i]];
    }
  }

  return matrix[5][n];
}

int main()
{
  int n;

  while (scanf("%d", &n) == 1) {
    long result = GetNumberOfWaysToMakeChange(n);

    if (result > 1)
      printf("There are %ld ways to produce %d cents change.\n", result, n);
    else
      printf("There is only 1 way to produce %d cents change.\n", n);
  }

  return 0;
}
