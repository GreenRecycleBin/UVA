#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 50

static int matrix[MAX_N + 2][MAX_N + 2], points[MAX_N + 2];

int CalculateCuts(int start, int end)
{
  if (matrix[start][end] != -1) return matrix[start][end];
  if (start + 1 == end) return 0;

  int i, min = INT_MAX;

  for (i = start + 1; i < end; ++i) {
    int cost = CalculateCuts(start, i) + CalculateCuts(i, end) + points[end] - points[start];

    if (cost < min) min = cost;
  }

  return matrix[start][end] = min;
}

int Solve(int n)
{
  memset(matrix, -1, sizeof matrix);

  return CalculateCuts(0, n + 1);
}

int main()
{
  int l, n;

  while (scanf("%d", &l) == 1 && l > 0) {
    int x, i;
    scanf("%d", &n);
    points[n + 1] = l;

    for (i = 1; i <= n; ++i)
      scanf("%d", points + i);

    printf("The minimum cutting is %d.\n", Solve(n));
  }

  return 0;
}
