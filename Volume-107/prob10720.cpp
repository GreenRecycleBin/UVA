#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

bool ErdosGallai(vector<int> &degrees)
{
  sort(degrees.begin(), degrees.end(), greater<int>());

  vector<int> cumulative_sums;
  cumulative_sums.push_back(degrees[0]);

  for (int i = 1; i < degrees.size(); ++i) {
    cumulative_sums.push_back(cumulative_sums[i - 1] + degrees[i]);
  }

  if (cumulative_sums.back() % 2 == 1) return false;

  bool has_simple_graph = false;
  int k = 1;

  do {
    int sum = k * (k - 1);

    for (int i = k; i < degrees.size(); ++i) sum += min(degrees[i], k);

    has_simple_graph = cumulative_sums[k - 1] <= sum;
    ++k;
  } while (k < degrees.size() && has_simple_graph);

  return has_simple_graph;
}

int main()
{
  vector<int> degrees;
  int n, x;

  while (scanf("%d", &n) == 1 && n > 0) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      degrees.push_back(x);
    }

    bool has_simple_graph = ErdosGallai(degrees);

    printf("%s\n", has_simple_graph ? "Possible" : "Not possible");

    degrees.clear();
  }

  return 0;
}
