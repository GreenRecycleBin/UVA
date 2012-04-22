#include <stdio.h>

int main()
{
  int n, i;
  scanf("%d", &n);

  for (i = 0; i < n; ++i) {
    int start, end, sum = 0;
    scanf("%d %d", &start, &end);

    if (start % 2 == 0) ++start;

    for (; start <= end; start += 2)
      sum += start;

    printf("Case %d: %d\n", i + 1, sum);
  }

  return 0;
}
