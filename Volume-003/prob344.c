#include <stdio.h>
#include <string.h>

enum kRomanChar {I, V, X, L, C};

static int ones[][5] =
  {
    {0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {2, 0, 0, 0, 0},
    {3, 0, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {2, 1, 0, 0, 0},
    {3, 1, 0, 0, 0},
    {1, 0, 1, 0, 0}
  };

static int tens[][5] =
  {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 3, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 3, 1, 0},
    {0, 0, 1, 0, 1}
  };

static int hundreds[][5] =
  {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1}
  };

static int num_chars[5];

int main()
{
  int n;

  while (scanf("%d", &n) == 1 && n > 0) {
    int i;

    for (i = 1; i <= n; ++i) {
      int hundred = i / 100, ten = i / 10, one = i % 10, j;

      for (j = 0; j < 5; ++j)
	num_chars[j] += hundreds[hundred][j] + tens[ten][j] + ones[one][j];
    }

    printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, num_chars[I], num_chars[V], num_chars[X], num_chars[L], num_chars[C]);

    memset(num_chars, 0, sizeof num_chars);
  }

  return 0;
}
