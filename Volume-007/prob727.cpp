#include <cstdio>
#include <stack>

using namespace std;

int main()
{
  int n;
  char c;
  stack<char> s;
  scanf("%d", &n);

  for (int i = 0; i < 2; ++i) getchar();

  for (int i = 0; i < n; ++i) {
    while ((c = getchar()) != '\n' && c != EOF) {
      switch (c) {
        case '+':
        case '-':
          while (!s.empty() && (s.top() == '+' || s.top() == '-' ||
                                s.top() == '*' || s.top() == '/')
                ) {
            putchar(s.top());
            s.pop();
          }

        case '*':
        case '/':
          while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
            putchar(s.top());
            s.pop();
          }

        case '(':
          s.push(c);

          break;

        case ')':
          while (!s.empty() && s.top() != '(') {
            putchar(s.top());
            s.pop();
          }

          s.pop();

          break;

        default:
          putchar(c);

          break;
      }

      getchar();
    }

    while (!s.empty()) {
      putchar(s.top());
      s.pop();
    }

    s = stack<char>();
    putchar('\n');

    if (i < n - 1) putchar('\n');
  }

  return 0;
}
