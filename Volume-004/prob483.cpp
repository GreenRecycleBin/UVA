#include <iostream>
#include <string>

using namespace std;

int main()
{
  string line;

  while (getline(cin, line)) {
    unsigned int i = 0;

    while (i < line.size()) {
      for(; line[i] == ' '; ++i);

      unsigned int start = i, end;

      for (end = start + 1; end < line.size() && line[end] != ' '; ++end);

      i = end;

      for (--end; end > start; ++start, --end) swap(line[start], line[end]);
    }

    cout << line << endl;
  }

  return 0;
}

