#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAX_N 26

static int char_counts[2][MAX_N];

int main()
{
  string inputs[2];

  while (getline(cin, inputs[0]) && getline(cin, inputs[1])) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < inputs[i].size(); ++j)
        ++char_counts[i][inputs[i][j] - 'a'];
    }

    for (int i = 0; i < MAX_N; ++i) {
      for (int j = 0; j < min(char_counts[0][i], char_counts[1][i]); ++j)
        putchar('a' + i);
    }

    putchar('\n');

    memset(char_counts, 0, sizeof char_counts);
  }

  return 0;
}
