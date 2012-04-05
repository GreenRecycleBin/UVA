#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
  char input[2000];

  while (fgets(input, sizeof(input), stdin)) {
    int i = 0, count = 0, size = strlen(input);

    while (1) {
      while (i < size && !isalpha(input[i])) ++i;

      if (i < size) ++count;
      else break;

      while (i < size && isalpha(input[i])) ++i;
    }

    printf("%d\n", count);
  }

  return 0;
}
