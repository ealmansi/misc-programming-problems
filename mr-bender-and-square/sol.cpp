/*
7333859  2014-08-03 06:32:57  apaapa   255D - Mr. Bender and Square  GNU C++  Accepted   62 ms   0 KB
http://codeforces.com/problemset/problem/255/D
*/

#include <iostream>
using namespace std;
typedef long long ll;

ll n, x, y, nx, ny, c;

ll u(ll x)
{
  if (x <= 0) return 0;
  else return x;
}

ll T(ll x)
{
  ll ans;
  x = u(x);
  if (x % 2 == 0) ans = (x / 2) * (x + 1);
  else ans = ((x + 1) / 2) * x;
  return ans;
}

int main(int argc, char const *argv[])
{
  cin >> n >> x >> y >> c;
  nx = (n-x+1), ny = (n-y+1);
  if (c == 1) cout << 0 << endl;
  else
  {
    ll low, t, high, on;
    low = 0, high = 2 * n;
    while (high - low > 1)
    {
      t = (high + low) / 2;
      on = 4 * T(t+1) - 2 * T(t+1-x) - 2 * T(t+1-y) - 2 * T(t+1-nx) - 2 * T(t+1-ny)
        + T(t+1-x-y) + T(t+1-x-ny) + T(t+1-nx-y) + T(t+1-nx-ny)
        - min(t+1, x) - min(t+1, y) - min(t+1, nx) - min(t+1, ny)
        + 1;
      if (c <= on) high = t; else low = t;
    }
    cout << high << endl;
  }
  return 0;
}