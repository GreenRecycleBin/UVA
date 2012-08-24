#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 99

static int row_sums[MAX_N], column_sums[MAX_N];

int main()
{
  int n;

  while(scanf("%d", &n) != EOF && n > 0) {
    memset(row_sums, 0, sizeof(row_sums[0]) * n);
    memset(column_sums, 0, sizeof(column_sums[0]) * n);

    int i, index_odd_row = -1, index_odd_column = -1;
    bool is_corrupt = false;

    for (i = 0; i < n; ++i) {
      int j;

      for (j = 0; j < n; ++j) {
        int input;
        scanf("%d", &input);
        row_sums[i] += input;
        column_sums[j] += input;
      }
    }

    for (i = 0; i < n; ++i) {
      if (row_sums[i] % 2 == 1) {
        if (index_odd_row == -1) index_odd_row = i;
        else is_corrupt = true;
      }

      if (column_sums[i] % 2 == 1) {
        if (index_odd_column == -1) index_odd_column = i;
        else is_corrupt = true;
      }
    }

    if (is_corrupt) printf("Corrupt\n");
    else if (index_odd_row != -1 && index_odd_column != -1) printf("Change bit (%d,%d)\n", index_odd_row + 1, index_odd_column + 1);
    else printf("OK\n");
  }

  return 0;
}

