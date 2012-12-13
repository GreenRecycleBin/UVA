#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 128;

struct Char
{
  char c;
  int frequency;
} static chars[MAX_N];

struct CharComparator
{
  bool operator()(const Char &a, const Char &b)
  {
    if (a.frequency == b.frequency) return a.c > b.c;

    return a.frequency < b.frequency;
  }
};

int main()
{
  string input;
  bool is_first_input = true;

  while (getline(cin, input)) {
    if (is_first_input) is_first_input = false;
    else putchar('\n');

    for (int i = 0; i < MAX_N; ++i) chars[i].c = i + 1;

    for (int i = 0; i < input.size(); ++i)
      ++chars[input[i] - 1].frequency;

    sort(chars, chars + MAX_N, CharComparator());

    size_t start = 0;

    while (chars[start].frequency == 0) ++start;

    for (int i = start; i < MAX_N; ++i)
      printf("%d %d\n", chars[i].c, chars[i].frequency);

    memset(chars, 0, sizeof chars);
  }

  return 0;
}
