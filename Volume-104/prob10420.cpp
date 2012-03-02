#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	map<string, set<string> > country_lovers_map;

	int n;
	cin >> n;

	while (n--) {
		string country, name;
		cin >> country;
		getline(cin, name);

		country_lovers_map[country].insert(name);
	}

	map<string, set<string> >::const_iterator it;

	for (it = country_lovers_map.begin(); it != country_lovers_map.end(); ++it) {
		cout << it->first << " " << it->second.size() << endl;
	}

	return 0;
}
