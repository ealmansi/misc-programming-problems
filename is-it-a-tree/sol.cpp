// http://www.spoj.com/problems/PT07Y/
// 20259679    2017-09-29 21:14:37 Is it a tree  accepted edit    ideone it 0.00  16M CPP14

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

#define rg(i, f, t) for (int i = f; i < t; ++i)

vi P;
vi R;

void make(int x)
{
  P[x] = x;
  R[x] = 0;
}

int find(int x)
{
  if (P[x] != x)
  {
    P[x] = find(P[x]);
  }
  return P[x];
}

void join(int x, int y)
{
  int px = find(x);
  int py = find(y);

  if (px == py)
  {
    return;
  }

  if (R[px] < R[py])
  {
    P[px] = py;
  }
  else if (R[px] > R[py])
  {
    P[py] = px;
  }
  else
  {
    P[py] = px;
    R[px] = R[px] + 1;
  }
}

void init(int N)
{
  P = vi(N);
  R = vi(N);
  rg(i, 0, N) make(i);
}

int main()
{
  int N, M;
  cin >> N >> M;
  init(N);
  rg(i, 0, M)
  {
    int u, v;
    cin >> u >> v; --u; --v;
    join(u, v);
  }
  if (M != N - 1)
  {
    cout << "NO" << endl;
    return 0;
  }
  rg(i, 0, N) if (find(i) != find(0))
  {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
