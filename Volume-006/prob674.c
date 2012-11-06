#include <stdio.h>

#define MAX_N 7489

static int denominators[] = {1, 5, 10, 25, 50};
static int M = sizeof denominators / sizeof denominators[0];

int main()
{
  int matrix[MAX_N + 1][M + 1], i, n;

  for (i = 0; i <= MAX_N; ++i) matrix[i][0] = 0;
  for (i = 1; i <= M; ++i) matrix[0][i] = 1;

  for (i = 1; i <= MAX_N; ++i) {
    int j;

    for (j = 1; j <= M; ++j)
      matrix[i][j] = matrix[i - denominators[j - 1]][j] + matrix[i][j - 1];
  }

  while (scanf("%d", &n) == 1)
    printf("%d\n", matrix[n][M]);

  return 0;
}
