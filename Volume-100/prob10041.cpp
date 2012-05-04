#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#define MAX_NUM_POINTS 500

static unsigned int points[MAX_NUM_POINTS];

int main()
{
  unsigned int n;
  cin >> n;

  while (n--) {
    unsigned int num_points;
    cin >> num_points;

    for (unsigned int i = 0; i < num_points; ++i)
      cin >> points[i];

    sort(points, points + num_points);

    unsigned int sum = 0, median;

    if (num_points % 2 == 0)
      median = (points[num_points / 2] + points[num_points / 2 - 1]) / 2;
    else
      median = points[num_points / 2];

    for (unsigned int i = 0; i < num_points; ++i)
      sum += abs((int)(median - points[i]));

    cout << sum << endl;
  }

  return 0;
}
