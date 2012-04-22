#include <stdio.h>

#define MAX_NUM_PEOPLE 1000

static int grades[MAX_NUM_PEOPLE];

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int num_people, i, sum = 0, average, count = 0;
    scanf("%d", &num_people);

    for (i = 0; i < num_people; ++i) {
      scanf("%d", &grades[i]);
      sum += grades[i];
    }

    average = sum / num_people;

    for (i = 0; i < num_people; ++i)
      if (grades[i] > average)
        ++count;

    printf("%.3lf%%\n", (double)count / num_people * 100);
  }

  return 0;
}
