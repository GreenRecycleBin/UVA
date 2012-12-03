#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1040
#define MAX_SIZE 21

static bool is_prime[MAX_N + 1];
static char input[MAX_SIZE + 1];

void Sieve(int n)
{
  memset(is_prime, 1, sizeof is_prime);

  int i;

  for (i = 2; i <= (int)sqrt(n); ++i) {
    if (is_prime[i]) {
      int j;

      for (j = i * i; j <= n; j += i)
	is_prime[j] = false;
    }
  }
}

int main()
{
  Sieve(MAX_N + 1);
  is_prime[0] = false;
  is_prime[1] = true;
  
  while (fgets(input, MAX_SIZE + 1, stdin) != NULL) {
    if (input[MAX_SIZE] == '\n') input[MAX_SIZE] = '\0';

    int i, size = strlen(input), value = 0;

    for (i = 0; i < size; ++i) {
      if ('a' <= input[i] && input[i] <= 'z')
	value += input[i] - 'a' + 1;
      else if ('A' <= input[i] && input[i] <= 'Z')
	value += input[i] - 'A' + 27;
    }

    if (is_prime[value]) printf("It is a prime word.\n");
    else printf("It is not a prime word.\n");
  }

  return 0;
}
