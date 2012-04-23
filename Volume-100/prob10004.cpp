#include <cassert>
#include <cmath>
#include <cstring>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define MAX_NUM_NODES 200

typedef unsigned int Node;

static bitset<MAX_NUM_NODES> adjacency_matrix[MAX_NUM_NODES];
static bitset<MAX_NUM_NODES> is_visited;

bool IsBicolorable(unsigned int num_nodes)
{
  assert(num_nodes > 1);

  map<Node, bool> sets[2];
  queue<Node> node_queue;
  is_visited.reset().flip();

  for (unsigned int i = 0; i < num_nodes; ++i) is_visited.flip(i);
  
  sets[0][0] = true;
  node_queue.push(0);
  
  do {
    Node v = node_queue.front();
    node_queue.pop();
    is_visited.set(v);

    vector<Node> nodes_in_other_set;
    
    for (unsigned int i = 0; i < num_nodes; ++i) {
      if (i != v && adjacency_matrix[v].test(i) && !is_visited[i]) {
	nodes_in_other_set.push_back(i);
	node_queue.push(i);
      }
    }

    if (sets[0].count(v) == 1) {
      for (unsigned int i = 0; i < nodes_in_other_set.size(); ++i) {
	if (sets[0].count(nodes_in_other_set[i]) == 1) return false;
	else sets[1][nodes_in_other_set[i]] = true;
      }
    }
    else if (sets[1].count(v) == 1) {
      for (unsigned int i = 0; i < nodes_in_other_set.size(); ++i) {
	if (sets[1].count(nodes_in_other_set[i]) == 1) return false;
	else sets[0][nodes_in_other_set[i]] = true;
      }
    }
  } while (!node_queue.empty());
    
  return true;
}

int main()
{
  unsigned int num_nodes;

  while (cin >> num_nodes && num_nodes > 0) {
    for (unsigned int i = 0; i < MAX_NUM_NODES; ++i)
      adjacency_matrix[i].reset();

    unsigned int num_edges;
    cin >> num_edges;

    for (unsigned int i = 0; i < num_edges; ++i) {
      Node nodes[2];
      cin >> nodes[0] >> nodes[1];

      adjacency_matrix[nodes[0]].set(nodes[1]);
      adjacency_matrix[nodes[1]].set(nodes[0]);
    }

    if (!IsBicolorable(num_nodes)) cout << "NOT ";

    cout << "BICOLORABLE." << endl;
  }

  return 0;
}
