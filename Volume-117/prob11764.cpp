#include <cstdio>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; ++i) {
    int n;
    scanf("%d", &n);

    int current_height;
    scanf("%d", &current_height);

    int num_low_jumps = 0;
    int num_high_jumps = 0;

    for (int j = 1; j < n; ++j) {
      int next_height;
      scanf("%d", &next_height);

      if (current_height < next_height) ++num_high_jumps;
      else if (current_height != next_height) ++num_low_jumps;

      current_height = next_height;
    }

    printf("Case %d: %d %d\n", i, num_high_jumps, num_low_jumps);
  }

  return 0;
}
