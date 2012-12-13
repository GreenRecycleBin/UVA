#include <cstdio>

using namespace std;

static int results[] =
  {2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

int main()
{
  int n;

  while (scanf("%d", &n) == 1 && n > 0)
    printf("%d\n", results[n - 1]);

  return 0;
}

/* Code to calculate answers below
#include <cstdio>
#include <list>

using namespace std;

const int MAX_N = 13;

static int results[MAX_N];
static int ids[MAX_N * 2];

int main()
{
  for (int i = 0; i < MAX_N * 2; ++i) ids[i] = i;

  for (int i = 1; i <= MAX_N; ++i) {
    int total = 2 * i, m = 1;

    do {
      list<int> people(ids, ids + total);
      list<int>::iterator it = people.begin();
      int num_bad_people = i;

      do {
        // Advance j 'm - 1' times
        for (int j = 0; j < (m - 1) % people.size(); ++j) {
          list<int>::iterator next = it;
          ++next;

          if (next == people.end()) next = people.begin();

          it = next;
        }

        // Kill a good guy
        if (*it < i) {
          ++m;

          break;
        }
        // Kill a bad guy
        else {
          list<int>::iterator next = it;
          ++next;

          if (next == people.end()) next = people.begin();

          people.erase(it);
          --num_bad_people;
          it = next;
        }
      } while (num_bad_people > 0);

      if (num_bad_people == 0) break;
    } while (true);

    results[i - 1] = m;
  }

  int n;

  while (scanf("%d", &n) == 1 && n > 0)
    printf("%d\n", results[n - 1]);

  return 0;
}
*/
