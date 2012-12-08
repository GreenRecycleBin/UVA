#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
  map<int, int> frequencies;
  vector<int> v;
  int n;

  while (scanf("%d", &n) == 1) {
    if (frequencies[n] == 0) v.push_back(n);

    ++frequencies[n];
  }

  for (int i = 0; i < v.size(); ++i)
    printf("%d %d\n", v[i], frequencies[v[i]]);

  return 0;
}
