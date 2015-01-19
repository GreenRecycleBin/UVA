#include <iostream>
#include <limits>

using namespace std;

int TotalScore(const string&);

int main() {
  int n;

  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (n-- > 0) {
    string line;

    getline(cin, line);

    cout << TotalScore(line) << endl;
  }

  return 0;
}

int TotalScore(const string& input) {
  int sum = 0;

  for (int i = 0, current = 0; i < input.size(); ++i) {
    switch (input[i]) {
    case 'O':
      ++current;
      sum += current;

      break;

    case 'X':
      current = 0;

      break;
    }
  }

  return sum;
}
