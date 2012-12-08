#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string inputs[2];

  while (getline(cin, inputs[0]) && getline(cin, inputs[1])) {
    long sums[2] = {0};

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < inputs[i].size(); ++j) {
        if (isalpha(inputs[i][j]))
          sums[i] += tolower(inputs[i][j]) - 'a' + 1;
      }
    }

    for (int i = 0; i < 2; ++i) {
      while (sums[i] > 9) sums[i] = sums[i] / 10 + sums[i] % 10;
    }

    double percentage;

    if (sums[0] < sums[1]) percentage = (double)sums[0] / sums[1];
    else percentage = (double)sums[1] / sums[0];

    printf("%.2lf %%\n", percentage * 100);
  }

  return 0;
}
