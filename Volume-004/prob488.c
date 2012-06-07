#include <stdio.h>
#include <stdbool.h>

void DrawWave(int amplitude, int frequency, bool is_last)
{
  int i;
  
  for (i = 0; i < frequency; ++i) {
    int j, k = 1;
    bool is_increasing = true;

    for (j = 0; j < amplitude * 2; ++j) {
      int l;
      
      for (l = 1; l <= k; ++l) {
	  printf("%d", k);
      }
      
      if (!is_last || i < frequency - 1 || j < amplitude * 2 - 1) {
	putchar('\n');
      }
      
      if (k == amplitude) {
	  is_increasing = false;
      }
      
      if (is_increasing) {
	++k;
      }
      else {
	--k;
      }
    }
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  while (n--) {
    int amplitude, frequency;
    scanf("%d %d", &amplitude, &frequency);

    

    if (n == 0) {
      DrawWave(amplitude, frequency, true);
    }
    else {
      DrawWave(amplitude, frequency, false);
    }
  }

  return 0;
}
