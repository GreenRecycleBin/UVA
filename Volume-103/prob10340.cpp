#include <iostream>
#include <string>

using namespace std;

bool IsSubsequence(string a, string b)
{
  int i = 0, j = -1;

  do {
    j = b.find(a[i], j + 1);
    ++i;
  } while (j != string::npos && i < a.size());

  if (j == string::npos) return false;
  else return true;
}

int main()
{
  string a, b;

  while (cin >> a >> b) {
    if (IsSubsequence(a, b)) cout << "Yes";
    else cout << "No";

    cout << endl;
  }

  return 0;
}
