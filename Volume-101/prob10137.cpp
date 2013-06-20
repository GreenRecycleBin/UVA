#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
  cout.setf(ios::fixed | ios::showpoint);
  cout.precision(2);
  int n;
  
  while (cin >> n && n > 0) {
    vector<double> expenses;
    
    for (int i = 0; i < n; ++i)
      expenses.push_back(*istream_iterator<double>(cin));
    
    double sum = accumulate(expenses.begin(), expenses.end(), 0.0);
    double average = sum / n;
    double amount_given = 0.0;
    double amount_received = 0.0;
    
    for (int i = 0; i < n; ++i) {
      double diff = expenses[i] - average;
      
      if (diff < 0)
        amount_received -= ceil(diff * 100) / 100;
      else
        amount_given += floor(diff * 100) / 100;
    }
    
    cout << "$" << max(amount_given, amount_received) << endl;
  }
  
  return 0;
}