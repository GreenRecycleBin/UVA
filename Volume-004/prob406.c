#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000
#define MAX_NUM_PRIMES 168 /* Number of primes less than 1000 */

static bool is_prime[MAX_N + 1];
static int primes[MAX_NUM_PRIMES];

void Sieve(int n)
{
  memset(is_prime, 1, sizeof is_prime);

  int i;

  for (i = 2; i <= (int)sqrt(n); ++i) {
    int j;

    if (is_prime[i]) {
      for (j = i * i; j <= n; j += i)
	is_prime[j] = false;
    }
  }
}

int main()
{
  Sieve(MAX_N);
  is_prime[1] = true;

  int last_index = -1, n, c;
  
  while (scanf("%d %d", &n, &c) == 2) {
    if (last_index < 0 || primes[last_index] < n) {
      int i;

      if (last_index < 0) i = 1;
      else i = primes[last_index] + 1;
      
      for (; i <= n; ++i) {
	if (is_prime[i]) primes[++last_index] = i;
      }
    }
    else {
      for(; primes[last_index] > n; --last_index);
    }

    int mid = last_index / 2, start, end, i;
    
    if ((last_index + 1) % 2 == 0) {
      start = mid - (c - 1);
      
      if (start < 0) {
	start = 0;
	end = last_index;
      }
      else {
	end = mid + c;
      }
    }
    else {
      start = mid - (c - 1);
      
      if (start < 0) {
	start = 0;
	end = last_index;
      }
      else {
	end = mid + c - 1;
      }
    }

    printf("%d %d:", n, c);
    
    for (i = start; i <= end; ++i)
      printf(" %d", primes[i]);

    puts("\n");
  }

  return 0;
}

