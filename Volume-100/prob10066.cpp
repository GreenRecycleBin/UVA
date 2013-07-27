#include <cstddef>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
size_t LongestCommonSubsequence(const vector<T>&, const vector<T>&);

int main() {
  vector<int> a;
  vector<int> b;

  for (int i = 1, m, n; scanf("%d %d", &m, &n) == 2 && m > 0 && n > 0; ++i) {
    a.resize(m);
    b.resize(n);

    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    printf("Twin Towers #%d\n", i);
    printf("Number of Tiles : %lu\n\n", LongestCommonSubsequence<int>(a, b));
  }

  return 0;
}

template<typename T>
size_t LongestCommonSubsequence(const vector<T> &a, const vector<T> &b) {
  // lcs[i][j]: Store the size of the longest common subsequence of
  // a[0..(i - 1)] and b[0..(j - 1)]
  vector<vector<size_t> > lcs(a.size() + 1);

  for (size_t i = 0; i < lcs.size(); ++i) lcs[i].resize(b.size() + 1);

  for (size_t i = 1; i < lcs.size(); ++i) {
    for (size_t j = 1; j < lcs[i].size(); ++j) {
      if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
      else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
    }
  }

  return lcs.back().back();
}
