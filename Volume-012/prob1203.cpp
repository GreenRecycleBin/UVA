#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

// Pair of (id, interval)
typedef pair<int, int> ii;

struct Comparator
{
  bool operator()(const ii &a, const ii &b)
  {
    if (a.second == b.second) return a.first > b.first;

    return a.second > b.second;
  }
};

typedef priority_queue<ii, vector<ii>, Comparator> pqii;
typedef map<int, int> mii;

int main()
{
  pqii pq;
  mii intervals;
  string input;
  int id, interval;

  while (cin >> input && input.size() > 1) {
    scanf("%d %d", &id, &interval);
    pq.push(ii(id, interval));
    intervals[id] = interval;
  }

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    ii next_job = pq.top();
    pq.pop();

    printf("%d\n", next_job.first);

    pq.push(ii(next_job.first, next_job.second += intervals[next_job.first]));
  }

  return 0;
}
