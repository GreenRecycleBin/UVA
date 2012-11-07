#include <cstdio>
#include <vector>

using namespace std;

void InitSet(vector<int> &set, int size)
{
  set.resize(size);

  for (int i = 0; i < size; ++i) set[i] = i;
}

int FindSet(vector<int> &set, int n)
{
  if (set[n] == n) return n;
  else set[n] = FindSet(set, set[n]);
}

void UnionSet(vector<int> &set, int i, int j)
{
  int set_j = FindSet(set, j);
  set[FindSet(set, i)] = set_j;
}

bool IsSameSet(vector<int> &set, int i, int j)
{
  return FindSet(set, i) == FindSet(set, j);
}

int main()
{
  vector<int> set;
  int n;
  scanf("%d", &n);

  while (n--) {
    int num_correct_queries = 0, num_queries = 0, num_computers;
    scanf("%d", &num_computers);
    InitSet(set, num_computers);
    getchar();

    for (int i = 0, c, x, y; (c = getchar()) != '\n' && c != EOF;) {
      scanf("%d %d", &x, &y);

      switch (c) {
        case 'c':
          UnionSet(set, x - 1, y - 1);

          break;

        case 'q':
          ++num_queries;

          if (IsSameSet(set, x - 1, y - 1)) ++num_correct_queries;

          break;
      }

      getchar();
    }

    printf("%d,%d\n", num_correct_queries, num_queries - num_correct_queries);

    if (n > 0) putchar('\n');

    set.clear();
  }

  return 0;
}
