#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000000

static bool is_prime[MAX_N + 2];

void Sieve(int n)
{
  int i;

  memset(is_prime, 1, sizeof is_prime);

  for (i = 2; i < (int)sqrt(n); ++i) {
    if (is_prime[i]) {
      int j;

      for (j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
}

int main()
{
  int n;
  Sieve(MAX_N);

  while (scanf("%d", &n) == 1) {
    if (is_prime[n]) {
      int temp = n;
      int reverse = 0;

      while (temp > 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
      }

      if (reverse != n && is_prime[reverse]) printf("%d is emirp.\n", n);
      else printf("%d is prime.\n", n);
    }
    else {
      printf("%d is not prime.\n", n);
    }
  }

  return 0;
}
