#include <stdio.h>

int main()
{
  int limit, id = 0;
  long num;

  while (scanf("%ld %d", &num, &limit) == 2 && num >= 0 && limit >= 0) {
    int count = 1;

    printf("Case %d: A = %d, limit = %d, ", ++id, (int)num, limit);

    while (num != 1 && num <= limit) {
      if (num % 2 == 0) num /= 2;
      else num = 3 * num + 1;

      ++count;
    }

    if (num > limit) --count;

    printf("number of terms = %d\n", count);
  }

  return 0;
}
