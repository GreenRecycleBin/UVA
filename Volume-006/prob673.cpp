#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  cin.ignore(1);

  while (n--) {
    string input;
    getline(cin, input);

    stack<char> s;
    bool is_balance = true;

    for (int i = 0; i < input.size(); ++i) {
      switch (input[i]) {
      case '(':
      case '[':
	s.push(input[i]);
	break;

      case ')':
      case ']':
	if (s.empty()) {
	  is_balance = false;
	  break;
	}
	else {
	  char top = s.top();
	  s.pop();

	  switch (input[i]) {
	  case ')':
	    if (top != '(') {
	      is_balance = false;
	      break;
	    }

	    break;

	  case ']':
	    if (top != '[') {
	      is_balance = false;
	      break;
	    }

	    break;
	  }

	  if (!is_balance) break;
	}

	break;
      }
    }

    if (!s.empty()) is_balance = false;

    if (is_balance) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
