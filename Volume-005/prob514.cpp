#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  vector<int> coaches;
  stack<int> s;
  int n, x;
  char c;

  while (scanf("%d", &n) == 1 && n > 0) {
    while (true) {
      for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        coaches.push_back(x);
      }

      int min = 1; // Minimum coach number on side A

      for (int i = 0; i < n; ++i) {
        // This coach is still on side A
        if (min <= coaches[i]) {
          // Push all the coach before this coach on side A to the stack
          for (; min < coaches[i]; ++min) s.push(min);

          // Move this coach to side B directly
          ++min;
        }
        // This coach can be popped to side B
        else if (!s.empty() && s.top() == coaches[i]) {
          s.pop();
        }
        else {
          break;
        }
      }

      if (s.empty()) printf("Yes\n");
      else printf("No\n");

      s = stack<int>();
      coaches.clear();

      // Get rid of new line and peek next character
      for (int i = 0; i < 2; ++i) c = getc(stdin);

      // We have reached the end of this input block
      if (c == '0') {
        break;
      }
      else {
        ungetc(c, stdin);

        continue;
      }
    }

    putchar('\n');
  }

  return 0;
}
