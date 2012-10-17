#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main()
{
  stack<int> stack;
  vector<queue<int> > queues;
  int num_tests;
  scanf("%d", &num_tests);

  for (int i = 0; i < num_tests; ++i) {
    int n, s, q;
    scanf("%d %d %d", &n, &s, &q);
    queues.assign(n, queue<int>());

    int queue_size, x, count;

    for (int j = 0; j < n; ++j) {
      scanf("%d", &queue_size);

      for (int k = 0; k < queue_size; ++k) {
        scanf("%d", &x);
        queues[j].push(x);
        ++count;
      }
    }

    int j = 0, time = 0;

    while (count > 0) {
      // Unload cargoes
      while (!stack.empty() && queues[j].size() < q) {
        if (stack.top() == j + 1) --count;
        else {
          queues[j].push(stack.top());
        }

        stack.pop();
        ++time;
      }

      // Platform B queue is full. However, we can still pop cargoes
      // to platform A
      while (!stack.empty() && stack.top() == j + 1) {
        stack.pop();
        --count;
        ++time;
      }

      // Load cargoes
      while (!queues[j].empty() && stack.size() < s) {
        stack.push(queues[j].front());
        queues[j].pop();
        ++time;
      }

      if (count > 0) {
        j = (j + 1) % n;
        time += 2;
      }
    }

    printf("%d\n", time);
    stack = std::stack<int>();
  }

  return 0;
}
