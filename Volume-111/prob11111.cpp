#include <cstdio>
#include <sstream>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
  stack<int> s;
  bool ok;
  string line;
  int n;

  while (getline(cin, line)) {
    ok = true;
    istringstream iss(line);

    while (iss >> n && ok) {
      if (n < 0) {
        s.push(n);
      }
      else if (n > 0) {
        int sum = 0;

        // Pop the stack and sum all the elements different from -n
        // This is the sum weight of all elements nested in current matrioshka
        while (!s.empty() && s.top() != -n) {
          if (s.top() > 0) {
            sum += s.top();
            s.pop();
          }
          // Nesting problem, top of stack matrioshka is not closed
          else {
            ok = false;

            break;
          }
        }

        if (ok) {
          // Pop the negative number and push the weight of this matrioshka
          if (!s.empty() && sum < n) {
            s.pop();
            s.push(n);
          }
          // No matching matrioshka found
          else {
            ok = false;
          }
        }
      }
    }

    if (ok) {
      // Our stack should contain only positive value
      while (!s.empty() && s.top() > 0) s.pop();

      if (!s.empty()) ok = false;
    }

    if (ok) printf(":-) Matrioshka!\n");
    else printf(":-( Try again.\n");

    s = stack<int>();
  }

  return 0;
}
