#include <cstdio>
#include <vector>

using namespace std;

int CalculateLengthOfLongestIncreasingSubsequence(const vector<int>&);
int IndexOfLeftMostElementGreaterThan(int, const vector<int>&);

int main() {
  int n;
  scanf("%d", &n);

  vector<int> events_to_indices(n);

  for (int i = 0, rank; i < n; ++i)
    scanf("%d", &events_to_indices[i]);

  // Current indices to original indices
  vector<int> indices_to_indices(n);

  for (int rank; scanf("%d", &rank) == 1;) {
    indices_to_indices[rank - 1] = events_to_indices[0];

    for (int i = 1; i < n; ++i) {
      scanf("%d", &rank);
      indices_to_indices[rank - 1] = events_to_indices[i];
    }

    printf("%d\n",
           CalculateLengthOfLongestIncreasingSubsequence(indices_to_indices));
  }

  return 0;
}

int CalculateLengthOfLongestIncreasingSubsequence(const vector<int> &v) {
  if (v.empty()) return 0;

  vector<int> t;
  t.push_back(v.front());

  for (int i = 1; i < v.size(); ++i) {
    int last = t.back();
    int current = v[i];

    if (current > last) t.push_back(current);
    else t[IndexOfLeftMostElementGreaterThan(current, t)] = current;
  }

  return t.size();
}

int IndexOfLeftMostElementGreaterThan(int key, const vector<int> &v) {
  int left = 0, right = v.size();

  while (left != right) {
    int middle = left + (right - left) / 2;
    int current = v[middle];

    if (current > key) right = middle;
    else left = middle + 1;
  }

  return right;
}
