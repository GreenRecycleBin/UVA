#include <algorithm>
#include <iostream>

using namespace std;

int TotalBottles(int);

int main() {
  int n;

  while (cin >> n) {
    cout << TotalBottles(n) << endl;
  }
}

int TotalBottles(int num_bottles) {
  int total = num_bottles;

  while (num_bottles >= 3) {
    int num_new_bottles = num_bottles / 3;
    total += num_new_bottles;
    num_bottles = num_new_bottles + num_bottles % 3;
  }

  if (num_bottles == 2)
    ++total;

  return total;
}
