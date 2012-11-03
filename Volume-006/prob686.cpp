#include <cstdio>
#include <bitset>
#include <vector>

using namespace std;

#define LIMIT 1 << 15

static bitset<LIMIT + 1> bs;
static vector<int> primes;

void Sieve(int limit)
{
  bs.reset();
  bs.flip();
  bs.reset(0);
  bs.reset(1);

  for (int i = 2; i <= limit + 1; ++i) {
    if (bs.test(i)) {
      for (int j = i * i; j <= limit + 1; j += i)
        bs.reset(j);

      primes.push_back(i);
    }
  }
}

int main()
{
  int n;

  Sieve(LIMIT);

  while (scanf("%d", &n) == 1 && n > 0) {
    int count = 0;

    for (int i = 0; i < primes.size() && primes[i] <= n / 2; ++i) {
      if (bs.test(n - primes[i])) ++count;
    }

    printf("%d\n", count);
  }

  return 0;
}
