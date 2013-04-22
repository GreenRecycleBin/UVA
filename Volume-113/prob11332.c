#include <stdio.h>

int main()
{
    int n;

    while (scanf("%d", &n) == 1 && n > 0) {
	while (n > 9) {
	    int sum = 0;

	    do {
		sum += n % 10;
		n /= 10;
	    } while (n > 0);

	    n = sum;
	}

	printf("%d\n", n);
    }

    return 0;
}
