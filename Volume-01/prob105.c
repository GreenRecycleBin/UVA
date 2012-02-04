#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_X 10000

int heights[MAX_X + 1];

int main()
{
  memset(heights, 0, MAX_X);

  int left, height, right, max = 0;

  while (scanf("%d %d %d", &left, &height, &right) != EOF) {
    int i;

    for (i = left; i < right; ++i) {
      if (heights[i] < height) {
        heights[i] = height;
      }
    }

    if (max < right) {
      max = right;
    }
  }

  int i, current_height = 0;
  bool not_first = false;

  for (i = 0; i < MAX_X; ++i) {
    if (heights[i] != current_height) {
      if (not_first) {
        putchar(' ');
      }
      else {
        not_first = true;
      }

      printf("%d %d", i, heights[i]);

      current_height = heights[i];
    }  
  }
      
  putchar('\n');

  return 0;
}
