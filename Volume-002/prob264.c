#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10000000

static int numerators[MAX_N], denominators[MAX_N];

int main()
{
  bool is_count_down = true;
  int count = 0, n = 1;

  while (count < MAX_N) {
    int i = 1, j = n;

    while (count < MAX_N && i <= n) {
      if (is_count_down) {
        numerators[count] = j--;
        denominators[count] = i++;
      }
      else {
        numerators[count] = i++;
        denominators[count] = j--;
      }

      ++count;
    }

    is_count_down = !is_count_down;
    ++n;
  }

  while(scanf("%d", &n) != EOF) {
    printf("TERM %d IS %d/%d\n", n, numerators[n - 1], denominators[n - 1]);
  }

  return 0;
}
