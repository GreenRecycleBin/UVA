#include <stdio.h>
#include <stdbool.h>

int main()
{
  int x, y, num_carries;
  bool has_carry;

  while (scanf("%d %d", &x, &y) != EOF && (x != 0 || y != 0)) {
    has_carry = false;
    num_carries = 0;

    while (x > 0 || y > 0) {
      int sum = x % 10 + y % 10;

      if (has_carry) ++sum;

      if (sum >= 10) {
        has_carry = true;
        ++num_carries;
      }
      else {
        has_carry = false;
      }

      x /= 10;
      y /= 10;
    }

    if (num_carries == 0 || num_carries == 1)
      printf("%s carry operation.\n", num_carries == 0 ? "No" : "1");
    else
      printf("%d carry operations.\n", num_carries);
  }

  return 0;
}
