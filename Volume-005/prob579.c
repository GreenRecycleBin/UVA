#include <stdio.h>

int main()
{
  int hour, minute;

  while (scanf("%d:%d", &hour, &minute) != EOF && (hour != 0 || minute != 0)) {
    double angle = (60 * hour - 11 * minute) / 2.0;

    if (angle < 0) angle = -angle;
    if (angle > 180) angle = 360 - angle;

    printf("%.3lf\n", angle);
  }

  return 0;
}
