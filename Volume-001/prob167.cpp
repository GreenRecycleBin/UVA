// Given the position of one queen at (a, b), write a program that will
// determine all posible placements of all other queens on the board
// such that no two queens attack each other. Display the output in
// lexicographical order.

#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

// There are 92 solutions to the 8-queen problem
#define NUM_SOLUTIONS 92
#define NUM_ROWS 8
#define NUM_COLS 8

int rows[NUM_COLS + 1], n, a, b, solutions[NUM_SOLUTIONS][NUM_COLS + 1], solution_count;

bool CanPlace(int col, int row)
{
  for (int prev = 1; prev < col; ++prev) {
    if (rows[prev] == row || abs(rows[prev] - row) == abs(prev - col))
      return false;
  }

  return true;
}

void Backtrack(int col)
{
  for (int row = 1; row <= NUM_ROWS; ++row) {
    if (CanPlace(col, row)) {
      if (col == b && row != a) continue;

      rows[col] = row;

      if (col == NUM_COLS && rows[b] == a) { // Found one solution
        for (int i = 1; i <= NUM_ROWS; ++i) solutions[solution_count][i] = rows[i];
        ++solution_count;
      }
      else Backtrack(col + 1);
    }
  }
}

int main()
{
  int boards[NUM_ROWS + 1][NUM_COLS + 1], max;

  // Find all solutions to the 8-queen problems
  b = 1, solution_count = 0;
  memset(solutions, 0, sizeof solutions);

  for (int row = 1; row <= NUM_ROWS; ++row) {
    a = row;
    memset(rows, 0, sizeof rows);
    Backtrack(1);

    if (n > 0) putchar('\n');
  }

  int n;
  scanf("%d", &n);

  while (n--) {
    max = 0;
    memset(boards, 0, sizeof boards);

    for (int i = 1; i <= NUM_ROWS; ++i) {
      for (int j = 1; j <= NUM_COLS; ++j) {
        scanf("%d", &boards[i][j]);
      }
    }

    int score;

    for (int i = 0; i < NUM_SOLUTIONS; ++i) {
      score = 0;

      for (int col = 1; col <= NUM_COLS; ++col) {
        score += boards[solutions[i][col]][col];
      }

      if (score > max) max = score;
    }

    printf("%5d\n", max);
  }

  return 0;
}
