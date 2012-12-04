#include <stdio.h>
#include <math.h>

int main()
{
  long n;
  int count;

  for (n = 8, count = 0; count < 10; ++n) {
    double x = sqrt((n * n + n) / 2);

    if ((int)x == x) {
      printf("%10ld%10ld\n", (long)x, n);
      ++count;
    }
  }

  return 0;
}
