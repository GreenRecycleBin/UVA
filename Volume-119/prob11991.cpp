#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef map<int, vi> mivi;

int main()
{
  mivi nth_positions;
  int n, m;

  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = 0, x; i < n; ++i) {
      scanf("%d", &x);

      nth_positions[x].push_back(i + 1);
    }

    for (int i = 0, position, x, index; i < m; ++i) {
      scanf("%d %d", &position, &x);

      if (nth_positions[x].size() < position) index = 0;
      else index = nth_positions[x][position - 1];

      printf("%d\n", index);
    }

    nth_positions = mivi();
  }

  return 0;
}
