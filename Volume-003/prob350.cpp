#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
  set<int> s;
  vector<int> v;

  int z, i, m, l, id = 1;

  while (scanf("%d %d %d %d", &z, &i, &m, &l) &&
         (z > 0 || i > 0 || m > 0 || l > 0)) {
    do {
      s.insert(l);
      v.push_back(l);

      l = ((z * l) + i) % m;
    } while (s.find(l) == s.end());

    printf("Case %d: %lu\n", id++, s.size() - (find(v.begin(), v.end(), l) - v.begin()));

    s.clear();
    v.clear();
  }

  return 0;
}
