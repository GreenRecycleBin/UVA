#include <stdio.h>

int NumberOfCuts(int row, int col)
{
  if (row == 1) return col - 1;

  return row - 1 + row * NumberOfCuts(1, col);
}

int main()
{
  int m, n;

  while (scanf("%d %d", &m, &n) == 2) {
    printf("%d\n", NumberOfCuts(m, n));
  }

  return 0;
}
