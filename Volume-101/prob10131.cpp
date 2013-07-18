#include <cstddef>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

struct Elephant {
  int id;
  int weight;
  int iq;

  Elephant(int id, int weight, int iq) : id(id), weight(weight), iq(iq) {}

  bool operator<(const Elephant &other) const {
    return weight < other.weight;
  }
};

struct ElephantComparator {
  bool operator()(const Elephant &a, const Elephant &b) {
    return a.iq >= b.iq;
  }
};

template<typename T>
class LongestIncreasingSubsequence {
 public:
  static vector<T> For(const vector<T> &v) {
    typedef typename vector<T>::const_iterator const_iterator;

    if (v.empty()) return vector<T>();

    // indices[i]: index of the smallest element that ends an increasing sequence
    // of length i + 1
    vector<size_t> indices;

    // parents[i]: index of the parent of the element with index i in the longest
    // increasing subsequence ending at the element with index i
    vector<size_t> parents;
    parents.reserve(v.size());

    // The longest increasing subsequence
    vector<T> lis;

    indices.push_back(0);
    parents.push_back(-1);

    for (size_t i = 1; i < v.size(); ++i) {
      const T &current = v[i];
      const T &last = v[indices.back()];

      if (last < current) {
        parents.push_back(indices.back());
        indices.push_back(i);
      }
      else {
        size_t index = IndexOfSmallestElementGreaterThan(current, indices, v);

        if (index == 0) parents.push_back(-1);
        else parents.push_back(indices[index - 1]);

        indices[index] = i;
      }
    }

    lis.reserve(indices.size());

    size_t current = indices.back();

    do {
      lis.push_back(v[current]);
      current = parents[current];
    } while (current != -1);

    return lis;
  }

 private:
  static size_t IndexOfSmallestElementGreaterThan(const T &key, const vector<size_t> &indices, const vector<T> &v) {
    size_t left = 0;
    size_t right = indices.size();

    while (left != right) {
      size_t middle = left + (right - left) / 2;
      const T &current = v[indices[middle]];

      if (key < current) right = middle;
      else left = middle + 1;
    }

    return right;
  }
};

int main() {
  vector<Elephant> elephants;

  for (int weight, iq, i = 1; scanf("%d %d", &weight, &iq) == 2; ++i)
    elephants.push_back(Elephant(i, weight, iq));

  sort(elephants.begin(), elephants.end(), ElephantComparator());

  vector<Elephant> lis = LongestIncreasingSubsequence<Elephant>::For(elephants);

  // Remove elephant with same weight
  set<Elephant> unique_lis(lis.begin(), lis.end());

  printf("%ld\n", unique_lis.size());

  for (set<Elephant>::const_iterator it = unique_lis.begin(); it != unique_lis.end(); ++it)
    printf("%d\n", it->id);

  return 0;
}
