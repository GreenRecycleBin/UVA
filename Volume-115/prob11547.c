#include <stdio.h>

int main()
{
  int t;
  scanf("%d", &t);

  while (t--) {
    double n;
    scanf("%lf", &n);
    n = (n * 567 / 9 + 7492) * 235 / 47 - 498;

    printf("%d\n", abs((int)n / 10 % 10));
  }

  return 0;
}
