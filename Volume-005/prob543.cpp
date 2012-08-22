#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define UPPER_LIMIT 1000000

int main()
{
  // Sieve of Eratosthenes
  bool is_prime[UPPER_LIMIT + 1];
  memset(is_prime, 1, sizeof(is_prime));

  for (int i = 2; i < sqrt(UPPER_LIMIT); ++i) {
    if (is_prime[i]) {
      int j = i * 2;
      
      while (j <= UPPER_LIMIT) {
        is_prime[j] = false;
        j += i;
      }
    }
  }

  set<int> primes;
  set<int>::iterator it = primes.end();

  for (int i = 2; i <= UPPER_LIMIT; ++i) {
    // Efficient insertion
    if (is_prime[i]) primes.insert(it, i);
  }

  int x;
  bool found;

  while (cin >> x && x > 0) {
    found = false;

    for (it = primes.begin(); it != primes.end(); ++it) {
      if (primes.find(x - *it) != primes.end()) {
        found = true;
        break;
      }
    }

    if (found) cout << x << " = " << (*it) << " + " << (x - *it) << endl;
    else cout << "Goldbach's conjecture is wrong." << endl;
  }
  
  return 0;
}
