#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100

static bool has_mines[MAX_ROW][MAX_COL];

int calculateSurroundingMines(int row, int col, int max_row, int max_col)
{
  int num_mines = 0;

  if (col - 1 >= 0) {
    if (has_mines[row][col - 1])
      ++num_mines;

    if (row - 1 >= 0 && has_mines[row - 1][col - 1])
      ++num_mines;

    if (row + 1 < max_row && has_mines[row + 1][col - 1])
      ++num_mines;
  }

  if (col + 1 < max_col) {
    if (has_mines[row][col + 1])
      ++num_mines;

    if (row - 1 >= 0 && has_mines[row - 1][col + 1])
      ++num_mines;

    if (row + 1 < max_row && has_mines[row + 1][col + 1])
      ++num_mines;
  }

  if (row - 1 >= 0 && has_mines[row - 1][col])
    ++num_mines;

  if (row + 1 < max_row && has_mines[row + 1][col])
    ++num_mines;

  return num_mines;
}

int main()
{
  int row, col, n = 0;
  char input[MAX_COL + 1];
  bool flag = false;

  while (scanf("%d %d", &row, &col) != EOF && row != 0 && col != 0) {
    int i, j;

    ++n;

    if (flag)
      putchar('\n');

    for (i = 0; i < row; ++i) {
      fgetc(stdin);
      fgets(input, col + 1, stdin);

      for (j = 0; j < col; ++j) {
        if (input[j] == '*')
          has_mines[i][j] = true;
        else
          has_mines[i][j] = false;
      }
    }

    printf("Field #%d:\n", n);

    for (i = 0; i < row; ++i) {
      for (j = 0; j < col; ++j) {
        if (has_mines[i][j]) {
          putchar('*');
        }
        else {
          int num_mines = calculateSurroundingMines(i, j, row, col);
          printf("%d", num_mines);
        }
      }

      putchar('\n');
    }

    flag = true;
  }

  return 0;
}
