#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

static const int MAX_N = 26;

static int soundex_code[MAX_N] =
{0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};

int main()
{
  string input;

  while (cin >> input) {
    for (int i = 0, last_code = 0; i < input.size(); ++i) {
      int code = soundex_code[input[i] - 'A'];

      if (code > 0 && code != last_code) printf("%d", code);

      last_code = code;
    }

    putchar('\n');
  }

  return 0;
}
