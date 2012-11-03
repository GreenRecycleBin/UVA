#include <cstdio>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
  deque<string> dq;
  string line, token;
  bool is_home;

  while (cin >> line) {
    is_home = true;
    int start_index = 0, end_index = line.find_first_of("[]", start_index);

    while (end_index != string::npos) {
      token = line.substr(start_index, end_index - start_index);

      if (!token.empty()) {
        if (is_home) dq.push_front(token);
        else dq.push_back(token);
      }

      switch (line[end_index]) {
        case '[':
          is_home = true;

          break;

        case ']':

          is_home = false;

          break;
      }

      start_index = end_index + 1;
      end_index = line.find_first_of("[]", start_index);
    }

    // Get the remaining token
    if (start_index < line.size()) {
      token = line.substr(start_index);

      if (is_home) dq.push_front(token);
      else dq.push_back(token);
    }

    while (!dq.empty()) {
      printf("%s", dq.front().c_str());
      dq.pop_front();
    }

    putchar('\n');
  }

  return 0;
}
