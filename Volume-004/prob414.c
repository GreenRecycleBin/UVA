#include <limits.h>
#include <stdio.h>

#define NUM_COLUMN 25

int main()
{
  int n;

  while (scanf("%d", &n) == 1 && n > 0) {
    int total = 0, min_num_spaces = INT_MAX, i;

    for (i = 0; i < n; ++i) {
      getchar();

      int j, num_spaces = 0;

      for (j = 0; j < NUM_COLUMN; ++j) {
        char c = getchar();

        if (c == ' ') ++num_spaces;
      }

      total += num_spaces;

      if (num_spaces < min_num_spaces) min_num_spaces = num_spaces;
    }

    printf("%d\n", total - n * min_num_spaces);
  }

  return 0;
}
