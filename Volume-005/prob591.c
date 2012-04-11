#include <stdio.h>

static int stacks[50];

int main()
{
  int n = 0, num_stacks;

  while (scanf("%d", &num_stacks) != EOF && num_stacks != 0) {
    int sum, average, count = 0, i;

    for (i = 0, sum = 0; i < num_stacks; ++i) {
      scanf("%d", &stacks[i]);
      sum += stacks[i];
    }

    average = sum / num_stacks;

    for (i = 0; i < num_stacks; ++i)
      if (stacks[i] < average) count += average - stacks[i];

    printf("Set #%d\n", ++n);
    printf("The minimum number of moves is %d.\n\n", count);
  }

  return 0;
}