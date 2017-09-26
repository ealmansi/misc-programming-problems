// 20233370  2017-09-27 00:31:00 emilio  Horrible Queries  accepted edit    ideone it 0.36  30M CPP14
// http://www.spoj.com/problems/HORRIBLE/

#include <iostream>
#include <vector>

using namespace std;

using lli = long long int;

using vi = vector<lli>;
using vvi = vector<vi>;

#define rg(i, f, t) for (lli i = f; i < t; ++i)

static const lli MAXN = 100005;
lli rmq[10 * MAXN];
lli lzy[10 * MAXN];

lli T;
lli N, C;
 
void init()
{
  rg(i, 0, 10 * N) rmq[i] = lzy[i] = 0;
}

lli left(lli i)
{
  return 2 * i + 1;
}

lli right(lli i)
{
  return 2 * i + 2;
}

lli mid(lli l, lli r)
{
  return (l + r) / 2;
}

void _update(lli i, lli l, lli r, lli p, lli q, lli v)
{
  if (r <= l || q <= p)
  {
    return;
  }
  rmq[i] += (q - p) * v;
  if (l == p && r == q)
  {
    lzy[left(i)] += v;
    lzy[right(i)] += v;
    return;
  }
  _update(left(i), l, mid(l, r), p, min(mid(l, r), q), v);
  _update(right(i), mid(l, r), r, max(mid(l, r), p), q, v);
}

void update(lli p, lli q, lli v)
{
  _update(0, 0, N, p - 1, q, v);
}

lli _query(lli i, lli l, lli r, lli p, lli q)
{
  if (r <= l || q <= p)
  {
    return 0;
  }
  if (lzy[i] > 0)
  {
    rmq[i] += (r - l) * lzy[i];
    lzy[left(i)] += lzy[i];
    lzy[right(i)] += lzy[i];
    lzy[i] = 0;
  }
  if (l == p && r == q)
  {
    return rmq[i];
  }
  return _query(left(i), l, mid(l, r), p, min(mid(l, r), q))
        + _query(right(i), mid(l, r), r, max(mid(l, r), p), q);
}

lli query(lli p, lli q)
{
  return _query(0, 0, N, p - 1, q);
}

int main()
{
  cin >> T;
  rg(t, 0, T)
  {
    cin >> N >> C;
    init();
    rg(i, 0, C)
    {
      lli c, p, q, v;
      cin >> c >> p >> q;
      if (c == 0)
      {
        cin >> v;
        update(p, q, v);
      }
      else {
        cout << query(p, q) << endl;
      }
    }
  }
  return 0;
}
