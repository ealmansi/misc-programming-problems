// Problem: Play On Words
/*
3722084 2014-08-02 15:04:41  Accepted 2016  C++ 280 276 apaapa Play on Words
http://poj.org/problem?id=1386
*/

#include <iostream>
#include <cmath>
using namespace std;
#define rep(k) for (int __ = 0; __ < k; ++__)
#define forr(i,d,h) for (int i = (d); i < (h); ++i)

#define AZSIZE ('z'-'a'+1)

int t, n, u, v;
string s;
bool present[AZSIZE];
int g[AZSIZE][AZSIZE];
int din[AZSIZE], dout[AZSIZE];
bool vst[AZSIZE];

void dfs(int u)
{
  vst[u] = true;
  forr(i, 0, AZSIZE) if (present[i])
    if (not vst[i] and (g[u][i] > 0 or g[i][u] > 0))
      dfs(i);
}

bool is_connected()
{
  fill(vst, vst + AZSIZE, false);
  dfs(0);
  forr(i, 0, AZSIZE) if (present[i])
    if (not vst[i])
      return false;
  return true;
}

void dfs_directed(int u)
{
  vst[u] = true;
  forr(i, 0, AZSIZE) if (present[i])
    if (not vst[i] and g[u][i] > 0)
      dfs_directed(i);
}

bool is_reachable(int u, int v)
{
  fill(vst, vst + AZSIZE, false);
  dfs(u);
  return vst[v];
}

int main(int argc, char const *argv[])
{
  cin >> t;
  rep(t)
  {
    fill(present, present + AZSIZE, false);
    forr(i, 0, AZSIZE) forr(j, 0, AZSIZE) g[i][j] = 0;
    fill(din, din + AZSIZE, 0);
    fill(dout, dout + AZSIZE, 0);

    cin >> n;
    rep(n)
    {
      cin >> s;
      u = s[0] - 'a';
      v = s[s.size() - 1] - 'a';
      present[u] = present[v] = true;
      ++g[u][v];
      ++dout[u];++din[v];
    }

    int extra_in = 0, extra_out = 0, fst = -1, lst = -1;
    forr(i, 0, AZSIZE)
      if (dout[i] > din[i]) { extra_out += dout[i] - din[i]; fst = i; }
      else if (din[i] > dout[i]) { extra_in += din[i] - dout[i]; lst = i; }

    if ((extra_in == 0 and extra_out == 0) and is_connected())
      cout << "Ordering is possible." << endl;
    else if ((extra_in == 1 and extra_out == 1) and is_reachable(fst, lst))
      cout << "Ordering is possible." << endl;
    else
      cout << "The door cannot be opened." << endl;
  }
  return 0;
}