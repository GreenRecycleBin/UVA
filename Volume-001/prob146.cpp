#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  string input;

  while (cin >> input && input.compare("#") != 0) {
    if (next_permutation(input.begin(), input.end())) cout << input << endl;
    else cout << "No Successor" << endl;
  }

  return 0;
}
