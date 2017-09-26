// 20231478  2017-09-26 19:16:54 emilio  Longest path in a tree  accepted edit    ideone it 0.00  16M CPP14
// http://www.spoj.com/problems/PT07Z/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

static const int MAXN = 10005;

using pii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;

#define mp make_pair
#define rg(i, f, t) for (int i = f; i < t; ++i)

int N;
int u, v;
vvi E(MAXN);
vb visited(MAXN);

pii _dfs(int u) {
  visited[u] = true;
  pii best_r = mp(u, 0);
  rg(i, 0, E[u].size()) if (!visited[E[u][i]]) {
    pii r = _dfs(E[u][i]);
    if (r.second + 1 > best_r.second) {
      best_r = mp(r.first, r.second + 1);
    }
  }
  return best_r;
}

pii dfs(int u) {
  rg(i, 1, N + 1) visited[i] = false;
  return _dfs(u);
}

int solve() {
  pii a = dfs(1);
  pii b = dfs(a.first);
  return b.second;
}

int main()
{
  cin >> N;
  rg(i, 0, N - 1) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  cout << solve() << endl;
  return 0;
}
