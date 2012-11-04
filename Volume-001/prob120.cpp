#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int a[30], n;
  string line;

  while (getline(cin, line)) {
    printf("%s\n", line.c_str());
    n = 0;

    const char *input = line.c_str();
    int num_read = 0;

    while (sscanf(input, "%d%n", a + n, &num_read) == 1) {
      input += num_read;
      ++n;
    }

    for (int i = 0; i < n - 1; ++i) {
      int *p = max_element(a, a + n - i);

      if (p - a != n - 1 - i) {
        if (p > a) {
          printf("%d ", (int)(n - (p - a)));
          reverse(a, p + 1);
        }

        printf("%d ", i + 1);
        reverse(a, a + n - i);
      }
    }

    printf("0\n");
  }

  return 0;
}
