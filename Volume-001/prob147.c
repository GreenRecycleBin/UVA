#include <stdbool.h>
#include <stdio.h>

#define MAX_N 30000
#define NUM_DENOMINATORS 11

static int denominators[NUM_DENOMINATORS + 1] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
static long num_ways[NUM_DENOMINATORS + 1][MAX_N + 1];

long GetNumberOfWaysForChange(int n)
{
  int i;

  for (i = 1; i <= n; ++i) num_ways[0][i] = 0;
  for (i = 0; i <= NUM_DENOMINATORS; ++i) num_ways[i][0] = 1;

  for (i = 1; i <= NUM_DENOMINATORS; ++i) {
    int j;

    for (j = 1; j <= n; ++j) {
      if (denominators[i] > j)
        num_ways[i][j] = num_ways[i - 1][j];
      else
        num_ways[i][j] = num_ways[i - 1][j] + num_ways[i][j - denominators[i]];
    }
  }

  return num_ways[NUM_DENOMINATORS][n];
}

int main()
{
  int dollars = 0, cents = 0;

  while (scanf("%d.%d", &dollars, &cents) == 2 && (dollars > 0 || cents > 0)) {
    printf("%3d.%02d%17ld\n", dollars, cents, GetNumberOfWaysForChange(dollars * 100 + cents));

    dollars = 0, cents = 0;
  }

  return 0;
}
