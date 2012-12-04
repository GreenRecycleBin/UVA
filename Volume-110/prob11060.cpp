#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef map<string, vs> msvs;
typedef map<string, bool> msb;
typedef map<string, int> msi;

vs nodes, nodes_in_topological_order;
msvs adjacent_list;
msb is_visited;
msi in_degrees;

void TopologicalSort()
{
  nodes_in_topological_order.clear();
  is_visited.clear();

  for (int i = 0; i < nodes.size(); ++i) {
    if (!is_visited[nodes[i]] && in_degrees[nodes[i]] == 0) {
      is_visited[nodes[i]] = true;
      nodes_in_topological_order.push_back(nodes[i]);

      for (int j = 0; j < adjacent_list[nodes[i]].size(); ++j)
        --in_degrees[adjacent_list[nodes[i]][j]];

      i = -1;
    }
  }
}

int main()
{
  int n, m, id = 0;
  string s[2];

  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      cin >> s[0];
      nodes.push_back(s[0]);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < 2; ++j) cin >> s[j];

      adjacent_list[s[0]].push_back(s[1]);
      ++in_degrees[s[1]];
    }

    TopologicalSort();

    printf("Case #%d: Dilbert should drink beverages in this order:", ++id);

    for (int i = 0; i < nodes_in_topological_order.size(); ++i) {
      printf(" %s", nodes_in_topological_order[i].c_str());
    }

    puts(".\n");

    nodes.clear();
    adjacent_list.clear();
    in_degrees.clear();
  }

  return 0;
}
