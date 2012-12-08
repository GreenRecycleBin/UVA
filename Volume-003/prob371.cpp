#include <cstdio>
#include <map>

using namespace std;

static map<long, long> sequence_length;

long GetSequenceLength(long n)
{
  if (sequence_length[n] > 0) return sequence_length[n];

  long count = 0, index = n;

  do {
    if (n % 2 == 0) n /= 2;
    else n = 3 * n + 1;

    ++count;
  } while (n != 1);

  sequence_length[index] = count;

  return count;
}

int main()
{
  long l, h;

  while (scanf("%ld %ld", &l, &h) == 2 && (l > 0 || h > 0)) {
    if (h < l) swap(h, l);

    long max_length = 0, max_n;

    for (long i = l; i <= h; ++i) {
      long length = GetSequenceLength(i);

      if (length > max_length) {
        max_length = length;
        max_n = i;
      }
    }

    printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", l, h, max_n, max_length);
  }

  return 0;
}
