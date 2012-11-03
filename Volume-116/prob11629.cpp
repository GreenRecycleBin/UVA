#include <cstdio>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

typedef numeric_limits<double> dbl;

int main()
{
  map<string, int> percentages;
  string input;
  double d;
  int p, g, integral, fractional;
  scanf("%d %d", &p, &g, &integral, &fractional);

  for (int i = 0; i < p; ++i) {
    cin >> input;
    scanf("%d.%d", &integral, &fractional);
    percentages[input] = integral * 10 + fractional;
  }

  for (int i = 0; i < g; ++i) {
    int percentage = 0;
    bool is_correct, has_more = true;

    do {
      cin >> input;
      percentage += percentages[input];
      cin >> input;

      if (input[0] != '+') {
        has_more = false;
        cin >> integral;
        integral *= 10;

        switch (input[0]) {
          case '<':
            if (input.size() > 1)
              is_correct = percentage <= integral;
            else
              is_correct = percentage < integral;

            break;

          case '>':
            if (input.size() > 1)
              is_correct = percentage >= integral;
            else
              is_correct = percentage > integral;

            break;

          case '=':
            is_correct = percentage == integral;

            break;
        }
      }
    } while (has_more);

    printf("Guess #%d was %s.\n", i + 1, is_correct ? "correct" : "incorrect");
  }

  return 0;
}
