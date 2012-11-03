#include <cstdio>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define MAX_ROOM 10

typedef pair<int, bitset<MAX_ROOM + 1> > ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, vi> mivi;

struct Compare
{
  bool operator()(const ii &a, const ii &b)
  {
    if (a.first != b.first)
      return a.first < b.first;

    return a.second.to_ulong() < b.second.to_ulong();
  }
};

enum StateType {WHITE, GREY, BLACK};

typedef set<ii, Compare> sii;
typedef map<ii, int, Compare> miii;
typedef map<ii, ii, Compare> miiii;

mivi adj_list, switch_adj_list;
miii dist, color;
miiii previous_state;

// In hallway with all lights off except the hallway's light
ii start_state(1, bitset<MAX_ROOM + 1>().set(1));

// Generate all state reachable from this state which are not visited before
void GenerateNeighbors(ii u, sii &next)
{
  // Move to next room when there is light in it
  for (int i = 0; i < adj_list[u.first].size(); ++i) {
    int next_room = adj_list[u.first][i];

    if (u.second.test(next_room)) {
      ii next_state(next_room, u.second);

    // This state is not visited before
    if (dist.find(next_state) == dist.end())
      next.insert(next_state);
    }
  }

  // Stay in current room and toggle switches in other room
  for (int i = 0; i < switch_adj_list[u.first].size(); ++i) {
    int next_light = switch_adj_list[u.first][i];

    // Don't turn off light in current room
    if (next_light != u.first) {
      // Turn on/off the light depends on current state
      bitset<MAX_ROOM + 1> next_bitset(u.second);

      if (u.second.test(next_light)) next_bitset.reset(next_light);
      else next_bitset.set(next_light);

      ii next_state(u.first, next_bitset);

      // This state is not visited before
      if (dist.find(next_state) == dist.end())
        next.insert(next_state);
    }
  }
}

bool Solve(int r)
{
  // In bedroom with all lights off except the bedroom's light
  ii end_state(r, bitset<MAX_ROOM + 1>().set(r));

  dist.clear();
  previous_state.clear();
  queue<ii> q;
  q.push(start_state);
  dist[start_state] = 0;

  while (!q.empty()) {
    ii u = q.front(); q.pop();

    if (u == end_state) return true;

    sii next;
    GenerateNeighbors(u, next);

    for (sii::iterator it = next.begin(); it != next.end(); ++it) {
      if (dist.find(*it) == dist.end()) {
        dist[*it] = dist[u] + 1;
        previous_state[*it] = u;
        q.push(*it);
      }
    }
  }

  return false;
}

void PrintSolution(int r)
{
  // In bedroom with all lights off except the bedroom's light
  ii end_state(r, bitset<MAX_ROOM + 1>().set(r));

  vii path;
  ii *current = &end_state;
  path.push_back(*current);

  while (*current != start_state) {
    path.push_back(previous_state[*current]);
    current = &previous_state[*current];
  }

  printf("The problem can be solved in %d steps:\n", dist[end_state]);

  // Path is stored backwards from end_state to start_state
  for (int i = path.size() - 1; i >= 1; --i) {
    ii &current = path[i];
    ii &next = path[i - 1];

    // In the same room
    if (current.first == next.first) {
      bitset<MAX_ROOM + 1> &current_bitset = current.second;
      bitset<MAX_ROOM + 1> &next_bitset = next.second;

      for (int i = 1; i <= MAX_ROOM; ++i) {
        // Find index of different bit
        if (current_bitset.test(i) && !next_bitset.test(i) ||
            !current_bitset.test(i) && next_bitset.test(i))
          printf("- Switch %s light in room %d.\n",
              next_bitset.test(i) ? "on" : "off", i);
      }
    }
    else {
      printf("- Move to room %d.\n", next.first);
    }
  }
}

int main()
{
  int r, d, s, u, v, id = 0;

  while(scanf("%d %d %d", &r, &d, &s) != EOF && (r > 0 || d > 0 || s > 0)) {
    adj_list.clear();
    switch_adj_list.clear();

    for (int i = 0; i < d; ++i) {
      scanf("%d %d", &u, &v);
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }

    for (int i = 0; i < s; ++i) {
      scanf("%d %d", &u, &v);
      switch_adj_list[u].push_back(v);
    }

    printf("Villa #%d\n", ++id);

    // There is a solution
    if (Solve(r)) PrintSolution(r);
    else printf("The problem cannot be solved.\n");

    putchar('\n');
  }
}
