#include <stdio.h>
#include <string.h>

#define NUM_PRIMES (sizeof(primes) / sizeof(primes[0]))

static unsigned int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

static unsigned int prime_counts[NUM_PRIMES];

void Factorize(unsigned int n){
  if (n == 0) return;

  int i = 0;

  while (n > 1 && i < NUM_PRIMES) {
    while (n % primes[i] == 0) {
      ++prime_counts[i];
      n /= primes[i];
    }

    ++i;
  }
}

void FactorizeFactorial(unsigned int n)
{
  memset(prime_counts, 0, sizeof(prime_counts));

  unsigned int i;

  for (i = 2; i <= n; ++i) Factorize(i);
}

int main()
{
  int n;

  while (scanf("%d", &n) != EOF && n > 0) {
    FactorizeFactorial(n);

    printf("%3u! =", n);

    int i;

    for (i = 0; i < NUM_PRIMES && prime_counts[i] > 0; ++i) {
      if (i > 0 && i % 15 == 0) printf("\n%6c", ' ');
      
      printf("%3u", prime_counts[i]);
    }

    putchar('\n');
  }

  return 0;
}
