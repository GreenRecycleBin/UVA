#include <cmath>
#include <cstdio>
#include <limits>

using namespace std;

int GetBranchingFactor(int, int);
int GetNumOfCatsWithHeightGreaterThanOne(int, int);
int GetHeightOfWholeCatTreeStack(int, int, int);

int main() {
  int initial_cat_height, num_cats_with_height_one;

  while (scanf("%d %d", &initial_cat_height, &num_cats_with_height_one) == 2 &&
         initial_cat_height != 0 && num_cats_with_height_one != 0) {
    int n = GetBranchingFactor(initial_cat_height,
                               num_cats_with_height_one);

    // Use this instead of log(num_cats_with_height_one) / log(n) to avoid
    // the case when n == 1
    int h = log(initial_cat_height) / log(n + 1);

    printf("%d %d\n", GetNumOfCatsWithHeightGreaterThanOne(n, h),
           GetHeightOfWholeCatTreeStack(n, h, initial_cat_height));
  }
}

// log(num_cats_with_height_one) / log(initial_cat_height) = log(n) / log(n + 1)
int GetBranchingFactor(int initial_cat_height, int num_cats_with_height_one) {
  double x = log(num_cats_with_height_one) / log(initial_cat_height);
  int n;

  for (n = 1; abs(log(n) / log(n + 1) - x) >= numeric_limits<double>::epsilon();
       ++n);

  return n;
}

// Total number of cats =
// (branching_factor ** (height + 1)) / (branching_factor - 1)
int GetNumOfCatsWithHeightGreaterThanOne(int branching_factor, int height) {
  if (branching_factor == 1) return height;
  else return (pow(branching_factor, height) - 1) / (branching_factor - 1);
}

int GetHeightOfWholeCatTreeStack(int branching_factor, int height,
                                 int initial_height) {
  double x = initial_height;

  for (int i = 1; i <= height; ++i)
    x += initial_height * pow(branching_factor, i) /
      pow(branching_factor + 1, i);

  return x;
}
