#include <stdio.h>

unsigned int f91(unsigned int n)
{
  while (n <= 100) {
    n += 11;
    
    if (n > 100) n -= 10;
  }

  return n - 10;
}

int main()
{
  unsigned int n;

  while (scanf("%u", &n) != EOF && n > 0) printf("f91(%u) = %u\n", n, f91(n));

  return 0;
}
