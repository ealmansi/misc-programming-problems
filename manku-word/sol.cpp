// Problem: Manku Word
// http://www.spoj.com/problems/MAY99_2/
// 13667848 2015-02-15 05:14:55 emilio  Manku Word  accepted   edit  run 0.00  3.2M   C++ 4.9
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int t;
unsigned long long int n;
string manku = "manku";

int main(int argc, char const *argv[])
{
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    string letters;
    while (n > 0) {
      --n;
      letters.push_back(manku[n % 5]);
      n = n / 5;
    }
    reverse(letters.begin(), letters.end());
    cout << letters << endl;
  }
  return 0;
}