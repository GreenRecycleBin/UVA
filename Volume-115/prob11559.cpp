#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>

#define MAX_NUM_HOTELS 18
#define MAX_NUM_WEEKS 13

using namespace std;

int main()
{
	int num_people, budget, num_hotels, num_weeks, price_per_person[MAX_NUM_HOTELS], num_beds_available[MAX_NUM_HOTELS][MAX_NUM_WEEKS], cost;

	while (cin >> num_people >> budget >> num_hotels >> num_weeks) {
		cost = INT_MAX;

		for (int i = 0; i < num_hotels; ++i) {
			cin >> price_per_person[i];

			for (int j = 0; j < num_weeks; ++j) {
				cin >> num_beds_available[i][j];
			}
		}

		for (int i = 0; i < num_hotels; ++i) {
			int max_beds_available = *max_element(&num_beds_available[i][0], &num_beds_available[i][num_weeks]);

			if (max_beds_available >= num_people) {
				if (price_per_person[i] * num_people < cost) cost = price_per_person[i] * num_people;
			}
		}

		if (cost <= budget) cout << cost << endl;
		else cout << "stay home" << endl;
	}

	return 0;
}