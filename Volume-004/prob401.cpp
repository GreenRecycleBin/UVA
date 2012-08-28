#include <iostream>
#include <map>
#include <string>

using namespace std;

bool IsPalindrome(string str)
{
  int i = 0, j = str.size() - 1;

  while (i < j) {
    if (str[i++] != str[j--]) return false;
  }

  return true;
}

bool IsMirroredString(string str, map<char, char> &mirror_character)
{
  int i = 0, j = str.size() - 1;

  while (i <= j) {
    if (mirror_character[str[i++]] != str[j--]) return false;
  }

  return true;
}

int main()
{
  map<char, char> mirror_character;
  mirror_character['A'] = 'A';
  mirror_character['E'] = '3';
  mirror_character['H'] = 'H';
  mirror_character['I'] = 'I';
  mirror_character['J'] = 'L';
  mirror_character['M'] = 'M';
  mirror_character['O'] = 'O';
  mirror_character['S'] = '2';
  mirror_character['T'] = 'T';
  mirror_character['U'] = 'U';
  mirror_character['V'] = 'V';
  mirror_character['W'] = 'W';
  mirror_character['X'] = 'X';
  mirror_character['Y'] = 'Y';
  mirror_character['Z'] = '5';
  mirror_character['1'] = '1';
  mirror_character['2'] = 'S';
  mirror_character['3'] = 'E';
  mirror_character['5'] = 'Z';
  mirror_character['8'] = '8';
  
  string input;
  
  while (cin >> input) {
    bool is_palindrome, is_mirrored_string;
    is_palindrome = IsPalindrome(input);
    is_mirrored_string = IsMirroredString(input, mirror_character);

    if (is_palindrome) {
      if (is_mirrored_string) cout << input << " -- is a mirrored palindrome." << endl;
      else cout << input << " -- is a regular palindrome." << endl;
    }
    else {
      if (is_mirrored_string) cout << input << " -- is a mirrored string." << endl;
      else cout << input << " -- is not a palindrome." << endl;
    }

    cout << endl;
  }

  return 0;
}
