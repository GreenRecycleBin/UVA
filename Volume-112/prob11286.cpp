#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  map<long long int, int> choices;
  int courses[5];
  int n;

  while (scanf("%d", &n) == 1 && n > 0) {
    int max = 0, count = 0;

    for (int i = 0; i < n; ++i) {
      long long mask = 0;

      for (int j = 0; j < 5; ++j) scanf("%d", courses + j);

      sort(courses, courses + 5);

      // 100-499: 400 choices -> 9 bits
      for (int j = 0; j < 5; ++j) mask = (mask << 9) | courses[j];

      if (++choices[mask] > max) max = choices[mask];
    }

    for (map<long long int, int>::const_iterator it = choices.begin();
        it != choices.end(); ++it) {
      if (it->second == max) count += max;
    }

    printf("%d\n", count);

    choices = map<long long int, int>();
  }

  return 0;
}
