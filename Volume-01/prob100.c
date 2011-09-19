#include <stdio.h>

int cycle_length(int n)
{
  int count = 1;

  while (n != 1) {
    ++count;

    if (n & 1 == 1) {
      n = 3 * n + 1; 
    }
    else {
      n >>= 1;
    }
  }

  return count;
}

int main()
{
  int first, second, max, curr_length;

  while (scanf("%d %d", &first, &second) != EOF) {
    max = 0;

    int start, end;

    if (first < second) {
      start = first;
      end = second;  
    }
    else {
      start = second;
      end = first;
    }
    
    int i;
    for (i = start; i <= end; i++) {
      curr_length = cycle_length(i); 

      max = curr_length > max ? curr_length : max;
    }

    printf("%d %d %d\n", first, second, max);
  }

  return 0;
}
