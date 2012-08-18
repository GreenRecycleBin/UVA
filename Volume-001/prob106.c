#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1000000

static bool flags[MAX_N + 1];

int gcd(int a, int b)
{
  if (a % b == 0) return b;
  else return gcd(b, a % b);
}

int main()
{
  int n;

  while (scanf("%d", &n) != EOF) {
    int p, num_relative_prime_triples = 0, num_excluded_integers = 0, i;

    memset(flags, 0, sizeof(flags));

    for (p = 2; p * p <= n; ++p) {
      int q;

      if (p % 2 == 0) q = 1;
      else q = 2;

      for (; q < p; q += 2) {
	int a = p * p - q * q, b = 2 * p * q, c = p * p + q * q, multiple = n / c, j;

	if (multiple >= 1 && gcd(a, b) == 1 && gcd(c, b) == 1) ++num_relative_prime_triples;

	for (i = 1; i <= multiple; ++i) {
	  flags[a * i] = true;
	  flags[b * i] = true;
	  flags[c * i] = true;
	}
      }
    }

    for (i = 1; i <= n; ++i) {
      if (!flags[i]) ++num_excluded_integers;
    }

    printf("%d %d\n", num_relative_prime_triples, num_excluded_integers);
  }

  return 0;
}
