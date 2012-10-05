#include <bitset>
#include <iostream>

using namespace std;

int main()
{
  int n;

  while (cin >> n) {
    bitset<32> input(n);
    bitset<32> output;

    for (int i = 0; i < 32; ++i) {
      if (input.test(31 - (i  / 8) * 8 - 7 + i % 8)) output.set(i);
    }

    cout << n << " converts to " << int(output.to_ulong()) << endl;
  }

  return 0;
}
