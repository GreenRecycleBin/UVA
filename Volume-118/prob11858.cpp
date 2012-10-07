#include <cmath>
#include <cstdio>

using namespace std;

#define MAX_N 1000000

void Merge(int *arr, int left, int right, unsigned long long &swap_count)
{
  int mid = floor((left + right) / 2), i1, i2, i3, temp[right - left + 1];
  i1 = 0;
  i2 = left;
  i3 = mid + 1;

  // number of time arr[i2] > arr[i3] so far
  int offset = 0;

  while (i2 <= mid && i3 <= right) {
    if (arr[i2] <= arr[i3]) {
      temp[i1++] = arr[i2++];
    }
    else { // Equivalent to swapping arr[i2] and arr[i3]
      swap_count += i3 - i2 - offset;
      temp[i1++] = arr[i3++];
      ++offset;
    }
  }

  while (i2 <= mid) temp[i1++] = arr[i2++];
  while (i3 <= right) temp[i1++] = arr[i3++];

  for (int i = left; i <= right; ++i) {
    arr[i] = temp[i - left];
  }
}

// Return number of swaps needed
unsigned long long MergeSort(int *arr, int left, int right)
{
  unsigned long long swap_count = 0;

  if (left < right) {
    int mid = floor((left + right) / 2);
    swap_count += MergeSort(arr, left, mid);
    swap_count += MergeSort(arr, mid + 1, right);
    Merge(arr, left, right, swap_count);
  }

  return swap_count;
}

int main()
{
  int nums[MAX_N], n;

  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &nums[i]);
    }

    printf("%llu\n", MergeSort(nums, 0, n - 1));
  }

  return 0;
}
