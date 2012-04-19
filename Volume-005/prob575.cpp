#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string input;

  while (cin >> input) {
    int x = 0;

    for (int i = 0; i < input.size(); ++i)
      x += (input[i] - '0') * (pow(2.0, (int)input.size() - i) - 1);

    if (x != 0) cout << x << endl;
    else break;
  }

  return 0;
}
