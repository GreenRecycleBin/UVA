#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<string> inputs;
  string line;
  int max_size = 0;

  while (getline(cin, line)) {
    if (line.size() > max_size) max_size = line.size();

    inputs.push_back(line);
  }

  for (int j = 0; j < max_size; ++j) {
    for (int i = inputs.size() - 1; i >= 0; --i) {
      if (j < inputs[i].size()) putchar(inputs[i][j]);
      else putchar(' ');
    }

    putchar('\n');
  }

  return 0;
}
