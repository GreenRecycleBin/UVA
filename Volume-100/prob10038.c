#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 3000

static int nums[MAX_N];
static bool flags[MAX_N];

int main()
{
  int n;

  while (scanf("%d", &n) != EOF) {
    int i;
    bool is_jolly = true;

    for (i = 0; i < n; ++i) scanf("%d", &nums[i]);

    memset(flags, 0, sizeof(flags));

    for (i = 1; i < n; ++i) {
      int abs_diff = abs(nums[i] - nums[i - 1]);
      if (abs_diff < 1 || abs_diff > n - 1 || flags[abs_diff]) {
	is_jolly = false;
	break;
      }
      else {
	flags[abs_diff] = true;
      }
    }

    if (is_jolly) printf("Jolly\n");
    else printf("Not jolly\n");
  }

  return 0;
}
