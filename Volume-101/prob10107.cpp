#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 10000

static unsigned int nums[MAX_N];

int main()
{
  int size = 0;

  while (cin >> nums[size++]) {
    sort(nums, nums + size);
    cout << (nums[(size - 1) / 2] + nums[size / 2]) / 2 << endl;
  }

  return 0;
}
