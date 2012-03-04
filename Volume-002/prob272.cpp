#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	char is_previous_open_quote = 0;

	while (getline(cin, line)) {
		int index = 0;

		while ((index = line.find("\"", index)) != string::npos) {
			line.erase(index, 1);

			if (is_previous_open_quote) line.insert(index, "''");
			else line.insert(index, "``");
			
			is_previous_open_quote = 1 - is_previous_open_quote;
			index += 2;
		}

		cout << line << endl;
	}

	return 0;
}