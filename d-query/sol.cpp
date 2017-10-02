// http://www.spoj.com/submit/DQUERY/
// 20260510 2017-09-30 01:33:04 emilio  D-query accepted edit    ideone it 0.29  20M CPP14

#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;

#define rg(i, f, t) for (int i = f; i < t; ++i)

const int MAX_N = 30005;
const int MAX_Q = 200005;
const int MAX_V = 1000005;

int N, Q;
vi a(MAX_N);
vi l(MAX_Q), r(MAX_Q);
int B;
int m[1000005];
vi idx(MAX_Q), ans(MAX_Q);

bool q_comp(int i, int j)
{
  int bi = l[i] / B;
  int bj = l[j] / B;
  return bi < bj || bi == bj && r[i] < r[j];
}

void solve()
{
  B = sqrt(N);
  rg(q, 0, Q) idx[q] = q;
  sort(idx.begin(), idx.begin() + Q, q_comp);
  int i = 0, j = -1, c, sz = 0;
  rg(q, 0, Q)
  {
    while (j < r[idx[q]]) c = ++m[a[++j]], sz += c == 1 ? 1 : 0;
    while (j > r[idx[q]]) c = --m[a[j--]], sz -= c == 0 ? 1 : 0;
    while (i > l[idx[q]]) c = ++m[a[--i]], sz += c == 1 ? 1 : 0;
    while (i < l[idx[q]]) c = --m[a[i++]], sz -= c == 0 ? 1 : 0;
    ans[idx[q]] = sz;
  }
}

int main()
{
  scanf("%d\n", &N);
  rg(n, 0, N)
  {
    scanf("%d", &a[n]);
  }
  scanf("%d\n", &Q);
  rg(q, 0, Q)
  {
    scanf("%d %d\n", &l[q], &r[q]);
    --l[q]; --r[q];
  }
  solve();
  rg(q, 0, Q)
  {
    printf("%d\n", ans[q]);
  }
  return 0;
}
