#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
  vi streets, avenues;
  int n, a, s, f, la, ls;
  scanf("%d", &n);

  while (n--) {
    scanf("%d %d %d", &a, &s, &f);
    streets.assign(f, 0);
    avenues.assign(f, 0);

    for (int i = 0; i < f; ++i) {
      scanf("%d %d", &ls, &la);
      streets[i] = ls;
      avenues[i] = la;
    }

    sort(streets.begin(), streets.end());
    sort(avenues.begin(), avenues.end());

    int median_index = (f - 1) / 2;

    printf("(Street: %d, Avenue: %d)\n", streets[median_index], avenues[median_index]);
  }

  return 0;
}
