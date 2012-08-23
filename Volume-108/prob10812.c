#include <stdio.h>

int main()
{
  int n, s, d;
  scanf("%d", &n);

  while (n--) {
    scanf("%d %d", &s, &d);

    int a = (s + d) / 2, b = s - a;

    if (a + b != s || a - b != d || a < 0 || b < 0) printf("impossible\n");
    else printf("%d %d\n", a, b);
  }

  return 0;
}
