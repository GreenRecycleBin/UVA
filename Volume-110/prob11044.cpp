#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int row;
    int column;
    cin >> row >> column;

    cout << (row / 3) * (column / 3) << endl;
  }

  return 0;
}
