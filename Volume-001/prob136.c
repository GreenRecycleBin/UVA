#include <stdio.h>

#define NUM_UGLY_NUMBERS 1500

int main()
{
	int ugly_numbers[NUM_UGLY_NUMBERS], p1 = 0, p2 = 0, p3 = 0, end = 0;
	ugly_numbers[0] = 1;

	while (end < NUM_UGLY_NUMBERS - 1) {
		while (ugly_numbers[p1] * 2 <= ugly_numbers[end]) ++p1;
		while (ugly_numbers[p2] * 3 <= ugly_numbers[end]) ++p2;
		while (ugly_numbers[p3] * 5 <= ugly_numbers[end]) ++p3;

		if (ugly_numbers[p1] * 2 < ugly_numbers[p2] * 3 &&
			ugly_numbers[p1] * 2 < ugly_numbers[p3] * 5)
			ugly_numbers[++end] = ugly_numbers[p1++] * 2;

		else if (ugly_numbers[p2] * 3 < ugly_numbers[p3] * 5)
			ugly_numbers[++end] = ugly_numbers[p2++] * 3;
		else
			ugly_numbers[++end] = ugly_numbers[p3++] * 5;
	}

	printf("The 1500'th ugly number is %d.\n", ugly_numbers[end]);

	return 0;
}