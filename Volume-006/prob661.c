#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 20

static bool flags[MAX_N];
static int powers[MAX_N];

int main()
{
  int n, m, c, id;

  for (id = 1; scanf("%d %d %d", &n, &m, &c) != EOF && (n != 0 || m != 0 || c != 0); ++id) {
    int i, total = 0, max = 0;

    memset(flags, 0, sizeof(flags));

    for (i = 0; i < n; ++i) scanf("%d", &powers[i]);

    for (i = 0; i < m; ++i) {
      int j;
      scanf("%d", &j);

      flags[j - 1] = !flags[j - 1];

      if (flags[j - 1]) {
	total += powers[j - 1];

	if (total > max) max = total;
      }
      else {
	total -= powers[j - 1];
      }
    }

    printf("Sequence %d\n", id);

    if (max > c) printf("Fuse was blown.\n");
    else printf("Fuse was not blown.\n"
		"Maximal power consumption was %d amperes.\n", max);

    putchar('\n');
  }

  return 0;
}
