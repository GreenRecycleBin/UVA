#include <cctype>
#include <iostream>

using namespace std;

#define MAX_SIZE 132

int main()
{
  string input;

  while (getline(cin, input)) {
    int total = 0;

    for (int i = 0; i < input.size(); ++i) {
      if (isdigit(input[i])) {
	total += input[i] - '0';
      }
      else if (input[i] == '!') {
	cout << endl;
      }
      else {
	if (input[i] == 'b') {
	  while (total--) cout << " ";
	}
	else {
	  while (total--) cout << input[i];
	}

	total = 0;
      }
    }

    cout << endl;
  }

  return 0;
}
