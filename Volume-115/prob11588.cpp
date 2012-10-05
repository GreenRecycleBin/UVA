#include <cstring>
#include <algorithm>
#include <iostream>

#define MAX_ROW 20
#define MAX_COLUMN 20
#define MAX_SIZE 26

using namespace std;

int main()
{
  int matrix[MAX_SIZE];
  int n;
  cin >> n;

  for (int id = 0; id < n; ++id) {
    memset(matrix, 0, sizeof(matrix));
    int row, column, m, n;
    cin >> row >> column >> m >> n;

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        char c;
        cin >> c;
        ++matrix[c - 'A'];
      }

      cin.ignore(1);
    }

    sort(matrix, matrix + MAX_SIZE);

    int i;
    for (i = MAX_SIZE - 2; matrix[i] == matrix[MAX_SIZE - 1] && i > 0; --i);

    int num_important_regions = MAX_SIZE - i - 1,
        num_other_positions = row * column - num_important_regions * matrix[MAX_SIZE - 1];


    cout << "Case " << id + 1 << ": " <<
            num_important_regions * matrix[MAX_SIZE - 1] * m +
            num_other_positions * n << endl;
  }

  return 0;
}
