#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000000000
#define NUM_PRIMES 3401

static bool is_prime[31622 + 1];
static int primes[NUM_PRIMES];

void Sieve(int n)
{
  int i, index;

  memset(is_prime, 1, sizeof is_prime);

  for (i = 2, index = 0; i <= (int)sqrt(n); ++i) {
    if (is_prime[i]) {
      int j;

      primes[index++] = i;

      for (j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }

  for (i = sqrt(n) + 1; i <= n && index < NUM_PRIMES; ++i) {
    if (is_prime[i]) primes[index++] = i;
  }
}

int GetNumDivisors(int n)
{
  int index = 0, num_divisors = 1;

  while (n > 0 && index < NUM_PRIMES) {
    int count = 0;

    while (n > 0 && n % primes[index] == 0) {
      n /= primes[index];
      ++count;
    }

    num_divisors *= (count + 1);
    ++index;
  }

  return num_divisors;
}

int main()
{
  int n, i;

  Sieve(sqrt(MAX_N));
  scanf("%d", &n);

  for (i = 0; i < n; ++i) {
    int l, u, max_num_divisors = INT_MIN, max, j;
    scanf("%d %d", &l, &u);

    for (j = l; j <= u; ++j) {
      int num_divisors = GetNumDivisors(j);

      if (num_divisors > max_num_divisors) {
        max_num_divisors = num_divisors;
        max = j;
      }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, max, max_num_divisors);
  }

  return 0;
}
