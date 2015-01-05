// Problem: Petya And Inequiations
/*
7303013  2014-08-01 04:22:45  apaapa   111A - Petya and Inequiations   GNU C++  Accepted   374 ms  0 KB
http://codeforces.com/problemset/problem/111/A
*/

#include <iostream>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

unsigned long long int N, X, Y;

int main(int argc, char const *argv[])
{
  cin >> N >> X >> Y;
  if (Y < N) { cout << -1 << endl; return 0; }
  if (not (N - 1 + (Y - N + 1) * (Y - N + 1) >= X)) { cout << -1 << endl; return 0; }
  cout << (Y - N + 1) << endl;
  forr(i, 0, N - 1) cout << 1 << endl;

  return 0;
}