#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef stack<int> si;

int num_nodes;
vi nodes_in_topological_order;
vvi adjacent_list;
vb is_visited;

void TopologicalVisit(int node)
{
  is_visited[node] = true;

  for (int i = 0; i < adjacent_list[node].size(); ++i) {
    if (!is_visited[adjacent_list[node][i]])
      TopologicalVisit(adjacent_list[node][i]);
  }

  nodes_in_topological_order.push_back(node);
}

void TopologicalSort()
{
  nodes_in_topological_order.clear();
  is_visited.assign(num_nodes, false);

  for (int i = 0; i < num_nodes; ++i) {
    if (!is_visited[i])
      TopologicalVisit(i);
  }
}

int main()
{
  int n, m;

  while (scanf("%d %d", &n, &m) == 2 && (n > 0 || m > 0)) {
    num_nodes = n;
    adjacent_list.assign(n, vi());

    for (int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);

      adjacent_list[x - 1].push_back(y - 1);
    }
    TopologicalSort();

    for (int i = nodes_in_topological_order.size() - 1; i >= 0; --i) {
      printf("%d", nodes_in_topological_order[i] + 1);

      if (i > 0) putchar(' ');
      else putchar('\n');
    }
  }

  return 0;
}
