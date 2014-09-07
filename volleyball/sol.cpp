/*
7288898 Practice:
apaapa  95C - 32  GNU C++ Accepted  1122 ms 21032 KB  2014-07-30 06:10:53 2014-07-30 06:10:53
http://codeforces.com/problemset/problem/95/C
*/

#include <cstdio>
#include <climits>
#include <utility>
#include <queue>
#include <list>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

typedef long long int lli;
typedef pair<lli,lli> pll;

#define MAX_N 2005

lli n, m;
lli x, y;
list<pll> junctions[MAX_N];
list<pll> viajes[MAX_N];
lli t[MAX_N], c[MAX_N];

bool visitado[MAX_N];
lli dist[MAX_N];

void dijkstra(list<pll> g[], lli src)
{
  fill(visitado, visitado + n, false);
  fill(dist, dist + n, LLONG_MAX);
  priority_queue<pll, vector<pll>, greater<pll> > cola;
  for (int j = 0; j < n; ++j)
    cola.push(make_pair(LLONG_MAX, j));
  
  dist[src] = 0;
  cola.push(make_pair(0, src));

  while (not cola.empty())
  {
    pll u_d = cola.top(); cola.pop();
    lli u = u_d.second, d = u_d.first;

    if (visitado[u]) continue;
    if (d == LLONG_MAX) break;
    visitado[u] = true;

    list<pll>::iterator it;
    for (it = g[u].begin(); it != g[u].end(); ++it)
    if (not visitado[it->first]) {
      if (dist[it->first] == LLONG_MAX or dist[u] + it->second < dist[it->first])
      {
        dist[it->first] = dist[u] + it->second;
        cola.push(make_pair(dist[u] + it->second, it->first));
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  cin >> n >> m;
  cin >> x >> y; --x; --y;

  for (int i = 0; i < m; ++i)
  {
    lli u, v, w;
    cin >> u >> v >> w; --u; --v;

    junctions[u].push_back(make_pair(v, w));
    junctions[v].push_back(make_pair(u, w));
  }

  for (int i = 0; i < n; ++i)
    cin >> t[i] >> c[i];

  for (int i = 0; i < n; ++i)
  {
    dijkstra(junctions, i);

    for (int j = 0; j < n; ++j) if (j != i)
      if (dist[j] <= t[i])
        viajes[i].push_back(make_pair(j, c[i]));
  }

  dijkstra(viajes, x);
  
  if (not visitado[y])
    cout << -1 << endl;
  else
    cout << dist[y] << endl;

  return 0;
}