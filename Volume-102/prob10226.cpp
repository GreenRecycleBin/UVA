#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<string, int> tree_count;
  string line;
  int n;
  scanf("%d", &n);
  cin.ignore(2);

  for (int i = 0; i < n; ++i) {
    int total_count = 0;

    while (getline(cin, line) && !line.empty()) {
      ++tree_count[line];
      ++total_count;
    }

    for (map<string, int>::const_iterator it = tree_count.begin();
        it != tree_count.end(); ++it)
        printf("%s %.4lf\n", it->first.c_str(),
              static_cast<double>(it->second) / total_count * 100);

    if (i < n - 1) putchar('\n');

    tree_count = map<string, int>();
  }

  return 0;
}
