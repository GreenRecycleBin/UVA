#include <stdio.h>
#include <stdbool.h>

static int carmichael_nums[] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};

int main()
{
  int n;

  while (scanf("%d", &n) == 1 && n > 0) {
    int i;
    bool is_carmichael = false;

    for (i = 0; i < sizeof carmichael_nums / sizeof carmichael_nums[0]; ++i) {
      if (n == carmichael_nums[i]) is_carmichael = true;
    }

    if (is_carmichael)
      printf("The number %d is a Carmichael number.\n", n);
    else
      printf("%d is normal.\n", n);
  }

  return 0;
}
