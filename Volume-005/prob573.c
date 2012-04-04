#include <stdbool.h>
#include <stdio.h>

int main()
{
	int h, d;
	double u, f;

	while(scanf("%d %lf %d %lf", &h, &u, &d, &f) && h != 0) {
		int day = 1;
		double current_height = 0.0;
		bool success = false;

		f = f / 100.0 * u;

		while (1) {
			current_height += u;

			if (current_height > h) {
				success = 1;
				break;
			}

			current_height -= d;

			if (current_height < 0) break;
			
			if (u > f) u -= f;
			else u = 0;

			++day;
		}

		if (success) printf("success ");
		else printf("failure ");
 
		printf("on day %d\n", day);
	}

	return 0;
}