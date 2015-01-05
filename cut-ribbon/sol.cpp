// Problem: Cut Ribbon
// 7698089  2014-09-07 07:11:15 apaapa  189A - Cut Ribbon GNU C++ Accepted  62 ms 100 KB
// http://codeforces.com/problemset/problem/189/A

#include <iostream>
#include <algorithm>
using namespace std;

// 4000

int n, a, b, c;

int mem[4005];

int f(int i)
{
  if (mem[i] == -1)
  {
    if (i == 0) mem[i] = 0;
    else
    {
      int res = -100000;
      if (a <= i) res = max(res, 1 + f(i - a));
      if (b <= i) res = max(res, 1 + f(i - b));
      if (c <= i) res = max(res, 1 + f(i - c));
      mem[i] = res;
    }
  }

  return mem[i];
}

int main(int argc, char const *argv[])
{
  cin >> n >> a >> b >> c;
  fill(mem, mem + n + 1, -1);
  cout << f(n) << endl;
  return 0;
}