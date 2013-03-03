#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int nums[3];

    for (int j = 0; j < 3; ++j) scanf("%d", nums + j);

    int minimum = min(nums[0], min(nums[1], nums[2]));
    int maximum = max(nums[0], max(nums[1], nums[2]));
    bool is_done = false;

    printf("Case %d: ", i + 1);

    for (int j = 0; !is_done && j < 3; ++j) {
      if (nums[j] != minimum && nums[j] != maximum) {
	is_done = true;
	printf("%d\n", nums[j]);
      }
    }

    if (!is_done) printf("%d\n", nums[2]);
  }

  return 0;
}
