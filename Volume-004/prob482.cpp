#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
  vector<int> indices;
  int n;
  cin >> n;
  cin.ignore(1);

  while (n--) {
    string lines[2];
    cin.ignore(1);
    getline(cin, lines[0]);
    getline(cin, lines[1]);

    istringstream iss1(lines[0]);
    int index;

    while (iss1 >> index) {
      indices.push_back(index);
    }

    string *numbers = new string[indices.size()];
    iss1.str(lines[1]);
    iss1.clear();
    string value;

    for (int i = 0; i < indices.size(); ++i) {
      iss1 >> value;
      numbers[indices[i] - 1] = value;
    }

    for (int i = 0; i < indices.size(); ++i) {
      cout << numbers[i] << endl;
    }

    if (n > 0) cout << endl;

    indices.clear();
    delete[] numbers;
  }

  return 0;
}
