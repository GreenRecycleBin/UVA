#include <iostream>
#include <list>

using namespace std;

int GetLastRegion(int n, int m)
{
  list<int> regions;

  for (int i = 1; i <= n; ++i) regions.push_back(i);

  while (regions.size() > 1) {
    regions.pop_front();

    for (int i = 1; i < m; ++i) {
      regions.push_back(regions.front());
      regions.pop_front();
    }
  }

  return regions.front();
}

int main()
{
  int n;

  while (cin >> n && n != 0) {
    int m = 1;

    while (GetLastRegion(n, m) != 13) ++m;

    cout << m << endl;
  }

  return 0;
}
