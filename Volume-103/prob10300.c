#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int num_farmers, sum = 0;
    scanf("%d", &num_farmers);

    while (num_farmers--) {
      int size, num_animals, rating;
      scanf("%d %d %d", &size, &num_animals, &rating);

      if (num_animals != 0)
        sum += size * rating;
    }

    printf("%d\n", sum);
  }

  return 0;
}
