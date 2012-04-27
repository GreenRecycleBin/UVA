#include <assert.h>
#include <math.h>
#include <stdio.h>

unsigned int SumOfDivisors(unsigned int n)
{
  assert(n > 0);

  if (n == 1) return 0;

  unsigned int i, sum = 1;

  for (i = 2; i < sqrt(n); ++i) {
    if (n % i == 0) {
      unsigned int a = n / i, b;
      sum += a;

      if ((b = n / a) != a) sum += b;
    }
  }

  return sum;
}

int main()
{
  unsigned int n;

  printf("PERFECTION OUTPUT\n");

  while (scanf("%u", &n) != EOF && n > 0) {
    unsigned sum_of_divisors = SumOfDivisors(n);

    printf("%5u  ", n);

    if (sum_of_divisors < n) printf("DEFICIENT");
    else if (sum_of_divisors == n) printf("PERFECT");
    else printf("ABUNDANT");

    putchar('\n');
  }
    
  printf("END OF OUTPUT\n");

  return 0;
}
