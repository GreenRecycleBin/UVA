#include <math.h>
#include <stdio.h>

int CountOneBinary(int n)
{
  int i, count = 0;
  for (i = 0; i < 32; ++i) {
    if (1 << i & n) ++count;
  }

  return count;
}

int DecToHex(int n)
{
  int i, last_digit, result = 0;
  for (i = 0; n > 0; n /= 10, ++i)
  {
    last_digit = n % 10;
    result += last_digit * pow(16, i);
  }

  return result;
}

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int x;
    scanf("%d", &x);

    printf("%d %d\n", CountOneBinary(x), CountOneBinary(DecToHex(x)));
  }

  return 0;
}
