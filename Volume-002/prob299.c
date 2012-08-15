#include <stdio.h>

int nums[50];

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int num, i, count = 0;
    scanf("%d", &num);

    for (i = 0; i < num; ++i)
      scanf("%d", &nums[i]);

    for (i = 1; i < num; ++i) {
      int j = i - 1, key = nums[i];

      while (j >= 0 && nums[j] > key) {
        nums[j + 1] = nums[j];
        --j;
      }

      if (i > j + 1)
        count += i - (j + 1);

      nums[j + 1] = key;
    }

    printf("Optimal train swapping takes %d swaps.\n", count);
  }

  return 0;
}
