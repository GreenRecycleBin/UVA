#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

static char matrix[MAX_SIZE][MAX_SIZE];
static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static bool is_visited[MAX_SIZE][MAX_SIZE];

void FloodFill(int row, int col, int max_row, int max_col, char c)
{
  if (row < 0 || row >= max_row || col < 0 || col >= max_col) return;

  matrix[row][col] = c;
  is_visited[row][col] = true;

  int i, new_row, new_col;

  for (i = 0; i < 8; ++i) {
    new_row = row + dx[i];
    new_col = col + dy[i];

    if (!is_visited[new_row][new_col] && matrix[new_row][new_col] == '@')
      FloodFill(new_row, new_col, max_row, max_col, c);
  }
}

int main()
{
  int m, n;

  while (scanf("%d %d", &m, &n) == 2 && (m > 0 || n > 0)) {
    int i, count = 0;

    for (i = 0; i < m; ++i) {
      getchar();

      int j;

      for (j = 0; j < n; ++j) scanf("%c", &matrix[i][j]);
    }

    for (i = 0; i < m; ++i) {
      int j;

      for (j = 0; j < n; ++j) {
        if (matrix[i][j] == '@') {
          FloodFill(i, j, m, n, '*');
          ++count;
        }
      }
    }

    printf("%d\n", count);
    memset(is_visited, 0, sizeof is_visited);
  }

  return 0;
}
