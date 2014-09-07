/*
7322859  Practice:
apaapa  103B - 22  GNU C++  Accepted   30 ms   148 KB 2014-08-02 03:17:34 2014-08-02 03:17:34
http://codeforces.com/problemset/problem/103/B
*/

#include <iostream>
#include <list>
using namespace std;
typedef list<int> li;
#define forr(i,d,h) for (int i = (d); i < (h); ++i)
#define MAXN 105
int N, M;
li g[MAXN];
bool vst[MAXN];

void bfs(int u)
{
  vst[u] = true;
  li::iterator it;
  for (it = g[u].begin(); it != g[u].end(); ++it) if (not vst[*it]) bfs(*it);
}

bool connected()
{
  fill(vst, vst + N, false);
  bfs(0);
  forr(i, 0, N) if (not vst[i]) return false;
  return true;
}

int main(int argc, char const *argv[])
{
  cin >> N >> M;

  int x, y;
  forr(i, 0, M)
  {
    cin >> x >> y; --x; --y;
    g[x].push_back(y); g[y].push_back(x);
  }
  if (connected() and N == M) cout << "FHTAGN!" << endl;
  else cout << "NO" << endl;
  return 0;
}