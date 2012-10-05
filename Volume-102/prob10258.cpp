#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>

#define NUM_CONTESTANTS 100
#define NUM_PROBLEMS 9

using namespace std;

typedef struct
{
  int id;
  int num_problem_solved;
  int penalty_time;
  // Penalty time for incorrect submissions
  int penalty_time_for_problem[NUM_PROBLEMS];
  bool has_submissions;
  bool has_solved_problem[NUM_PROBLEMS];
} Contestant;

struct Compare
{
  bool operator()(const Contestant &a, const Contestant &b) {
    if (a.num_problem_solved != b.num_problem_solved)
      return a.num_problem_solved > b.num_problem_solved;

    if (a.penalty_time != b.penalty_time)
      return a.penalty_time < b.penalty_time;

    return a.id < b.id;
  }
} compare;

int main()
{
  Contestant contestants[NUM_CONTESTANTS];

  int n;
  cin >> n;
  cin.ignore(2);

  while (n--) {
    memset(contestants, 0, sizeof(contestants));

    for (int i = 0; i < NUM_CONTESTANTS; ++i) contestants[i].id = i;

    string input;
    int id, problem_id, time;
    char l;

    while (getline(cin, input) && !input.empty()) {
      istringstream iss1(input);
      iss1 >> id >> problem_id >> time >> l;
      Contestant &current = contestants[id - 1];

      if (!current.has_submissions) current.has_submissions = true;

      // Do nothing if this problem has been solved
      if (!current.has_solved_problem[problem_id - 1]) {
        if (l == 'C') {
          ++current.num_problem_solved;
          current.penalty_time +=
            current.penalty_time_for_problem[problem_id - 1];
          current.penalty_time += time;
          current.has_solved_problem[problem_id - 1] = true;
        }
        else if (l == 'I') {
          current.penalty_time_for_problem[problem_id - 1] += 20;
        }
      }
    }

    sort(contestants, contestants + NUM_CONTESTANTS, compare);

    for (int i = 0; i < NUM_CONTESTANTS; ++i) {
      if (contestants[i].has_submissions)
        cout << contestants[i].id + 1 << " " << contestants[i].num_problem_solved <<
                " " << contestants[i].penalty_time << endl;
    }

    if (n > 0) cout << endl;
  }

  return 0;
}
