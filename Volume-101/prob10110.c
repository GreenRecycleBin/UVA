#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool IsPerfectSquare(unsigned int n)
{
  int root = sqrt(n);

  return n == pow((double)root, 2);
}

int main()
{
  unsigned int n;

  while (scanf("%u", &n) != EOF && n > 0) {
    if (IsPerfectSquare(n)) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}
