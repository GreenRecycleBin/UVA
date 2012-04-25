#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int x, y;
    scanf("%d %d", &x, &y);

    if (x < y) putchar('<');
    else if (x == y) putchar('=');
    else putchar('>');

    putchar('\n');
  }

  return 0;
}
