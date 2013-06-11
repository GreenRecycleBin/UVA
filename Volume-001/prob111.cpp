#include <cstdio>
#include <vector>

using namespace std;

int LongestIncreasingSubsequenceLength(const vector<int>&);
int MaximumIndexOfTailLessThan(const vector<int>&, int, int);

const int MAX_N = 20;

int main()
{
  int n;
  scanf("%d", &n);
  
  vector<int> events_to_indices(MAX_N);
  
  for (int i = 0, rank; i < n; ++i)
    scanf("%d", &events_to_indices[i]);
  
  // Current indices to original indices
  vector<int> indices_to_indices(MAX_N);
  
  for (int rank; scanf("%d", &rank) == 1;) {
    indices_to_indices[rank - 1] = events_to_indices[0];
    
    for (int i = 1; i < n; ++i) {
      scanf("%d", &rank);
      indices_to_indices[rank - 1] = events_to_indices[i];
    }
    
    printf("%d\n", LongestIncreasingSubsequenceLength(indices_to_indices));
  }
  
  return 0;
}

int LongestIncreasingSubsequenceLength(const vector<int> &v)
{
  int size = v.size(), length;
  vector<int> tails(size);
  tails[0] = v[0];
  length = 1;
  
  for (int i = 1; i < size; ++i) {      
    // New minimum value
    if (v[i] < tails[0])
      tails[0] = v[i];
    else if (v[i] > tails[length - 1])
    // Extend the largest subsequence
      tails[length++] = v[i];
    else
      tails[MaximumIndexOfTailLessThan(tails, length, v[i])] = v[i];
  }
  
  return length;
}

int MaximumIndexOfTailLessThan(const vector<int> &v, int size, int key)
{
  // Check the last element first when the vector have only two elements
  int left = -1, right = size - 1, middle;
  
  // Return when the list have only one element
  while (left + 1 < right) {
    middle = left + (right - left) / 2;
    
    (v[middle] >= key ? right : left) = middle;
  }
  
  return right;
}
