#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  map<char, int> char_count;
  int max_count;
  string input;

  while(getline(cin, input)) {
    char_count.clear();
    max_count = 0;

    for (int i = 0; i < input.size(); ++i) {
      if (isalpha(input[i]) && ++char_count[input[i]] > max_count) max_count = char_count[input[i]];
    }

    map<char, int>::const_iterator it;

    for (it = char_count.begin(); it != char_count.end(); ++it) {
      if (it->second == max_count) cout << it->first;
    }

    cout << " " << max_count << endl;
  }

  return 0;
}
