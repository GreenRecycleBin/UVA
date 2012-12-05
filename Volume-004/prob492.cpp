#include <cstdio>
#include <cctype>
#include <string>

using namespace std;

string ConvertToPigLatin(const string &s)
{
  if (s.empty()) return "";

  char first_char = tolower(s[0]);

  string ret = s;

  switch (first_char) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      break;

    default:
      ret = s.substr(1, string::npos) + s[0];
  }

  return ret + "ay";
}

int main()
{
  char c;
  string word;

  while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
      word += c;
    }
    else {
      fputs(ConvertToPigLatin(word).c_str(), stdout);
      word.clear();
      putchar(c);
    }
  }

  fputs(ConvertToPigLatin(word).c_str(), stdout);

  return 0;
}
