#include <cstdio>
#include <functional>
#include <queue>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > pq_type;

int main()
{
  int n, x;
  pq_type pq;

  while (scanf("%d", &n) == 1 && n > 0) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      pq.push(x);
    }

    int total_cost = 0;

    for (int i = 0; i < n - 1; ++i) {
      int top1 = pq.top();
      pq.pop();
      int top2 = pq.top();
      pq.pop();
      total_cost += top1 + top2;

      pq.push(top1 + top2);
    }

    printf("%d\n", total_cost);
    pq = pq_type();
  }

  return 0;
}
