#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string input;

  while (cin >> input) {
    for (int i = 0; i < input.size(); ++i) {
      switch (input[i]) {
        case '-':
        case '0':
        case '1':
          putchar(input[i]);

          break;

        default:
          if ('A' <= input[i] && input[i] <= 'O')
            printf("%d", (input[i] - 'A') / 3 + 2);
          else if (input[i] && input[i] <= 'S') putchar('7');
          else if (input[i] && input[i] <= 'V') putchar('8');
          else if (input[i] <= 'Z') putchar('9');

          break;
      }
    }

    putchar('\n');
  }

  return 0;
}
