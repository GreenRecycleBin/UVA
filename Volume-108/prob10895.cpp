#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef map<int, vi> mivi;

int main()
{
  mivi indices, values;
  vector<int> column_indices;
  int row, column;

  while (scanf("%d %d", &row, &column) == 2) {
    for (int i = 0; i < row; ++i) {
      int num_elements;
      scanf("%d", &num_elements);
      column_indices.clear();

      for (int j = 0; j < num_elements; ++j) {
        int index;
        scanf("%d", &index);
        indices[index].push_back(i + 1);
        column_indices.push_back(index);
      }

      for (int j = 0; j < num_elements; ++j) {
        int value;
        scanf("%d", &value);
        values[column_indices[j]].push_back(value);
      }
    }

    printf("%d %d\n", column, row);

    for (int i = 1; i <= column; ++i) {
      printf("%d", (int)indices[i].size());

      if (indices[i].size() == 0) {
        printf("\n\n");

        continue;
      }
      else {
        putchar(' ');
      }

      for (int j = 0; j < indices[i].size(); ++j) {
        printf("%d", indices[i][j]);

        if (j < indices[i].size() - 1) putchar(' ');
        else putchar('\n');
      }

      for (int j = 0; j < values[i].size(); ++j) {
        printf("%d", values[i][j]);

        if (j < values[i].size() - 1) putchar(' ');
        else putchar('\n');
      }
    }

    indices = values = mivi();
  }

  return 0;
}
