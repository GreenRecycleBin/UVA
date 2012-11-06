#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 20

static int num_votes[MAX_N];
static bool is_taken[MAX_N];
static int results[MAX_N];

void Compute(int index, int size, int sum, int limit)
{
  int i;

  for (i = 0; i < size; ++i) {
    if (is_taken[i]) continue;

    is_taken[i] = true;

    if (sum + num_votes[i] > limit) ++results[i];
    else if (i >= index) Compute(i, size, sum + num_votes[i], limit);

    is_taken[i] = false;
  }
}

void Solve(int size, int limit)
{
  memset(results, 0, sizeof results);
  memset(is_taken, 0, sizeof is_taken);

  Compute(0, size, 0, limit);
}

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int size, i, total_num_votes = 0;
    scanf("%d", &size);

    for (i = 0; i < size; ++i) {
      scanf("%d", num_votes + i);
      total_num_votes += num_votes[i];
    }

    Solve(size, total_num_votes / 2);

    for (i = 0; i < size; ++i)
      printf("party %d has power index %d\n", i + 1, results[i]);

    putchar('\n');
  }

  return 0;
}
