#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef struct {
  int frequency;
  char character;
} my_struct;

#define MAX_NUM_CHARACTERS 26

bool compare(my_struct a, my_struct b)
{
  if (a.frequency > b.frequency) return true;
  else if (a.frequency == b.frequency && a.character < b.character) return true;
  else return false;
}

int main()
{
  my_struct structs[MAX_NUM_CHARACTERS];

  for (int i = 0; i < MAX_NUM_CHARACTERS; ++i) {
    structs[i].frequency = 0;
    structs[i].character = i + 'A';
  }

  int n;
  cin >> n;
  cin.ignore(1);

  string input;

  while (n--) {
    getline(cin, input);

    for (int i = 0; i < input.size(); ++i) {
      unsigned int index = toupper(input[i]) - 'A';

      if (index < MAX_NUM_CHARACTERS)
	++structs[index].frequency;
    }
  }

  sort(structs, structs + MAX_NUM_CHARACTERS, compare);

  for (int i = 0; i < MAX_NUM_CHARACTERS && structs[i].frequency > 0; ++i)
    cout << structs[i].character << " " << structs[i].frequency << endl;

  return 0;
}
