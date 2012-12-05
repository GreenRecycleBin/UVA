#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool IsDividedBy11(const string &input)
{
  int sum = 0;

  for (int i = 0; i < input.size(); ++i) {
    if (i % 2 == 0) sum += input[i] - '0';
    else sum -= input[i] - '0';
  }

  return sum % 11 == 0;
}

int main()
{
  string input;

  while(cin >> input && (input.size() > 1 || atoi(input.c_str()) > 0)) {
    if (IsDividedBy11(input))
      printf("%s is a multiple of 11.\n", input.c_str());
    else
      printf("%s is not a multiple of 11.\n", input.c_str());
  }

  return 0;
}
