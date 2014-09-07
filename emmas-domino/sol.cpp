/*
12070178   2014-08-02 08:28:25  emilio  Emma s Domino  accepted  edit  run 0.50   407M  C++ 4.3.2
http://www.spoj.com/problems/TAP2012E/
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define forr(i,d,h) for (int i = (d); i < (h); ++i)

#define MAXN 1005
#define MAXH 55
#define MAXD 105
#define INF 10000

int N, H;
int D[MAXN], P[MAXN];
int mem[MAXN][MAXN*MAXD];

int f(int i, int p)
{
  if (mem[i][p] == -1)
  {
    if (i == N - 2) mem[i][p] = (p + H < P[i+1]) ? INF : 0;
    else if (p + H < P[i+1]) mem[i][p] = 1 + f(i + 1, p + H);
    else
    {
      int res = f(i + 1, P[i+1]);
      forr(j, 1, p + H - P[i+1] + 1) res = min(res, 1 + f(i + 1, P[i+1] + j));
      mem[i][p] = res;
    }
  }
  return mem[i][p];
}

int main(int argc, char const *argv[])
{
  cin >> N >> H;
  while (N != -1)
  {
    forr (i, 1, N) cin >> D[i];
    P[0] = 0; forr (i, 1, N) P[i] = P[i - 1] +  D[i];

    forr(i, 0, N) forr(j, 0, P[N-1]) mem[i][j] = -1;
    int res = f(0, P[0]);
    if (INF <= res) cout << -1 << endl;
    else cout << res << endl;

    cin >> N >> H;
  }
  return 0;
}