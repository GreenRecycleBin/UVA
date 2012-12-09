#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

static const int MAX_N = 10;
static map<string, int> net_worth;
static string names[MAX_N];

int main()
{
  int n;
  bool is_first_case = true;

  while (scanf("%d", &n) == 1) {
    if (!is_first_case) putchar('\n');

    for (int i = 0; i < n; ++i) cin >> names[i];

    for (int i = 0; i < n; ++i) {
      string name;
      int initial_money, give_amount = 0, num_people;

      cin >> name >> initial_money >> num_people;

      if (num_people > 0) {
        give_amount = initial_money / num_people;
        initial_money = -(initial_money - initial_money % num_people);
      }
      else {
        initial_money = 0;
      }

      net_worth[name] += initial_money;

      for (int j = 0; j < num_people; ++j) {
        cin >> name;
        net_worth[name] += give_amount;
      }
    }

    for (int i = 0; i < n; ++i)
      printf("%s %d\n", names[i].c_str(), net_worth[names[i]]);

    is_first_case = false;
    net_worth.clear();
  }

  return 0;
}
