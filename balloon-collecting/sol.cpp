// Problem: Balloon Collecting
// 1538040  5068  Balloon Collecting  Accepted  C++ 0.003 2014-09-07 03:01:37
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3069

#include <iostream>
#include <cmath>
using namespace std;

#define iter(i, d, h) for (int i = (d); i < (h); ++i)
#define INF ((int)1e9)

#define MAXN 45
#define MAXK 3

int n, max_i;
int p[MAXN+1], t[MAXN+1];

int mem[MAXN+1][MAXK + 1];

int f(int i, int k)
{
  if (mem[i][k] == -1)
  {
    int ans = INF;
    if (i == n)
    {
      ans = p[n];
    }
    else
    {
      int alt1 = INF, alt2 = INF;
      int dp = abs(p[i + 1] - p[i]), dt = abs(t[i + 1] - t[i]);
      if (k < MAXK and dp * (k + 1) <= dt) alt1 = f(i + 1, k + 1);
      if (p[i] * (k + 1) + p[i + 1] * (0 + 1) <= dt) alt2 = f(i + 1, 1);
      if (alt1 < INF) ans = min(ans, dp + alt1);
      if (alt2 < INF) ans = min(ans, p[i] + p[i + 1] + alt2);
    }
    max_i = max(max_i, i);
    mem[i][k] = ans;
  }
  return mem[i][k];
}

int main(int argc, char const *argv[])
{
  cin >> n;
  while (n != 0)
  {
    max_i = 0;
    iter(i, 0, n + 1) iter(j, 0, MAXK + 1) mem[i][j] = -1;
    
    p[0] = t[0] = 0;
    iter(i, 1, n + 1) cin >> p[i] >> t[i];

    int ans = f(0, 0);
    if (max_i == n) cout << "OK " << ans << endl;
    else cout << "NG " << (max_i + 1) << endl;

    cin >> n;
  }
  return 0;
}