#include <climits>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

static const int MAX_NUM_BOXES = 30;
enum Color {WHITE, GREY, BLACK};

struct Box
{
  static const int MAX_NUM_DIMENSIONS = 10;
  int id, num_dimensions;
  Color color;

  // Box a can be nested in box b
  // Assume a and b's dimensions are sorted beforehand
  // Assume a and b have same number of dimensions
  static bool CanBeNested(const Box &a, const Box &b)
  {
    for (int i = 0; i < a.num_dimensions; ++i) {
      if (a.dimensions[i] >= b.dimensions[i]) return false;
    }

    return true;
  }

  int dimensions[MAX_NUM_DIMENSIONS];
} static boxes[MAX_NUM_BOXES];

struct BoxComparator
{
  // Two boxes have same number of dimensions
  bool operator()(const Box &a, const Box &b)
  {
    for (int i = 0; i < a.num_dimensions; ++i) {
      if (a.dimensions[i] == b.dimensions[i]) continue;
      else return a.dimensions[i] < b.dimensions[i];
    }

    return true;
  }
};

// sizes[i]: size of Longest Increasing Subsequence ending at boxes[i]
static int sizes[MAX_NUM_BOXES], parent[MAX_NUM_BOXES];

int LIS(int k) {
  int max_index = 0, max = 1;

  memset(parent, -1, sizeof parent);

  for (int i = 0; i < k; ++i) sizes[i] = 1;

  for (int i = 0; i < k - 1; ++i) {
    for (int j = i + 1; j < k; ++j) {
      if (Box::CanBeNested(boxes[i], boxes[j]) && sizes[i] + 1 > sizes[j]) {
        sizes[j] = sizes[i] + 1;

        if (sizes[j] > max) {
          max = sizes[j];
          max_index = j;
        }

        parent[j] = i;
      }
    }
  }

  return max_index;
}

void PrintBox(const Box &a)
{
  printf("Box %d:", a.id);

  for (int i = 0; i < a.num_dimensions; ++i) printf(" %d", a.dimensions[i]);

  putchar('\n');
}

int main()
{
  int k, n;

  while (scanf("%d %d", &k, &n) == 2) {
    for (int i = 0; i < MAX_NUM_BOXES; ++i) {
      boxes[i].id = i + 1;
      boxes[i].color = WHITE;
    }

    int max_nested_size = INT_MIN, max_nested_sequence[MAX_NUM_BOXES];

    for (int i = 0; i < k; ++i) {
      boxes[i].num_dimensions = n;

      for (int j = 0; j < n; ++j) {
        scanf("%d", boxes[i].dimensions + j);
      }

      sort(boxes[i].dimensions, boxes[i].dimensions + boxes[i].num_dimensions);
    }

    sort(boxes, boxes + k, BoxComparator());
    int max_index = LIS(k);

    printf("%d\n", sizes[max_index]);

    vector<int> trace;

    do {
      trace.push_back(boxes[max_index].id);
      max_index = parent[max_index];
    } while (max_index >= 0);

    for (int i = trace.size() - 1; i >= 0; --i) {
      printf("%d", trace[i]);

      if (i > 0) putchar(' ');
      else putchar('\n');
    }
  }

  return 0;
}
