#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main()
{
  stack<int> s;
  queue<int> q;
  priority_queue<int> pq;
  int n, c, x;

  while (scanf("%d", &n) == 1) {
    bool is_stack = true, is_queue = true, is_priority_queue = true;

    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &c, &x);

      if (c == 1) {
        if (is_stack) s.push(x);
        if (is_queue) q.push(x);
        if (is_priority_queue) pq.push(x);
      }
      else {
        if (is_stack && !s.empty() && s.top() == x) s.pop();
        else is_stack = false;

        if (is_queue && !q.empty() && q.front() == x) q.pop();
        else is_queue = false;

        if (is_priority_queue && !pq.empty() && pq.top() == x) pq.pop();
        else is_priority_queue = false;
      }
    }

    if (!is_stack && !is_queue && !is_priority_queue) printf("impossible\n");
    else if (is_stack && !is_queue && !is_priority_queue) printf("stack\n");
    else if (is_queue && !is_stack && !is_priority_queue) printf("queue\n");
    else if (is_priority_queue && !is_stack && !is_queue) printf("priority queue\n");
    else printf("not sure\n");

    s = stack<int>();
    q = queue<int>();
    pq = priority_queue<int>();
  }

  return 0;
}
