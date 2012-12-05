#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NUM_PRIMES 4792

static bool is_prime[46340];
static int primes[NUM_PRIMES];

void Sieve(int n)
{
  int i, index = 0;

  memset(is_prime, 1, sizeof is_prime);

  for (i = 2; i <= (int)sqrt(n); ++i) {
    if (is_prime[i]) {
      primes[index++] = i;

      int j;

      for (j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }

  for (i = (int)sqrt(n) + 1; index < NUM_PRIMES && i <= n; ++i) {
    if (is_prime[i]) primes[index++] = i;
  }
}

int main()
{
  Sieve(sqrt(INT_MAX));

  int n;

  while (scanf("%d", &n) && n != 0) {
    printf("%d =", n);

    if (n < 0) {
      printf(" -1 x");
      n = -n;
    }

    int index = 0, root = sqrt(n);

    while (n > 0 && index < NUM_PRIMES && primes[index] <= root) {
      while (n > 0 && n % primes[index] == 0) {
        printf(" %d", primes[index]);
        n /= primes[index];

        if (n > 1) fputs(" x", stdout);
      }

      ++index;
    }

    if (n > 1)
      printf(" %d", n);

    putchar('\n');
  }

  return 0;
}
