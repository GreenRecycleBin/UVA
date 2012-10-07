#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_AGE 100

int main()
{
  int n, nums[MAX_AGE + 1], x;

  while (scanf("%d", &n) != EOF && n > 0) {
    memset(nums, 0, sizeof nums);

    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      ++nums[x];
    }

    int last;

    for (last = MAX_AGE; nums[last] == 0; --last);

    for (int i = 1; i <= MAX_AGE; ++i) {
      if (nums[i] > 0) {
        for (int j = 0; j < nums[i]; ++j) {
          printf("%d", i);

          if (j < nums[i] - 1 || i < last) putchar(' ');
        }
      }
    }

    putchar('\n');
  }

  return 0;
}
