#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
  char first_row[] = { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=' };
  char second_row[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\' };
  char third_row[] = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'' };
  char fourth_row[] = { 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/' };

  vector<vector<char> > rows;
  rows.push_back(vector<char>(first_row, first_row + sizeof(first_row) / sizeof(char)));
  rows.push_back(vector<char>(second_row, second_row + sizeof(second_row) / sizeof(char)));
  rows.push_back(vector<char>(third_row, third_row + sizeof(third_row) / sizeof(char)));
  rows.push_back(vector<char>(fourth_row, fourth_row + sizeof(third_row) / sizeof(char)));

  vector<map<char, int> > char_to_int_maps(rows.size(), map<char, int>());

  for (int i = 0; i < rows.size(); ++i) {
    for (int j = 0; j < rows[i].size(); ++j) {
      char_to_int_maps[i][rows[i][j]] = j;
    }
  }

  string input;

  while(getline(cin, input)) {
    for (int i = 0; i < input.size(); ++i) {
	    int row_index = -1;

      for (int j = 0; j < rows.size(); ++j) {
        if (char_to_int_maps[j].find(input[i]) != char_to_int_maps[j].end()) {
          row_index = j;
          break;
        }
      }

      if (row_index == -1) {
        cout << input[i];
      }
      else {
        cout << rows[row_index][char_to_int_maps[row_index][input[i]] - 1];
      }
    }

    cout << endl;
  }

  return 0;
}
