#include <cstdio>
#include <string>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int m;
    scanf("%d", &m);

    char digits[m][2];

    for (int i = 0; i < m; ++i)
      scanf("%*c%c %c", digits[i], digits[i] + 1);

    char result[m];
    bool has_carry = false;

    for (int i = m - 1; i >= 0; --i) {
      int sum = digits[i][0] + digits[i][1] - 2 * '0';

      if (has_carry) {
        ++sum;
        has_carry = false;
      }

      if (sum > 9) {
        has_carry = true;
        sum %= 10;
      }

      result[i] = '0' + sum;
    }

    if (has_carry) putchar('1');

    for (int i = 0; i < m; ++i) putchar(result[i]);

    putchar('\n');

    if (n > 0) putchar('\n');
  }

  return 0;
}
