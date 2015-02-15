// Problem: Amusing numbers
// http://www.spoj.com/problems/TSHOW1/
// 13667862 2015-02-15 05:19:00 emilio  Amusing numbers accepted   edit  run 0.00  3.2M   C++ 4.9
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int t;
unsigned long long int n;
string amusing = "56";

int main(int argc, char const *argv[])
{
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    string letters;
    while (n > 0) {
      --n;
      letters.push_back(amusing[n % 2]);
      n = n / 2;
    }
    reverse(letters.begin(), letters.end());
    cout << letters << endl;
  }
  return 0;
}