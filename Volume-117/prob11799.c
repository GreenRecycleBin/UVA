#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		int num_students, max_speed, j;
		scanf("%d", &num_students);

		for (j = 0, max_speed = 0; j < num_students; ++j) {
			int temp;
			scanf("%d", &temp);

			if (temp > max_speed) max_speed = temp;
		}

		printf("Case %d: %d\n", i + 1, max_speed);
	}

	return 0;
}
