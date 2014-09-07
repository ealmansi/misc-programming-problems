/*
12320327  2014-09-07 05:22:02 emilio  Can you answer these queries I  accepted   edit  run 3.20  9.1M   C++ 4.3.2
// http://www.spoj.com/problems/GSS1/
*/

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long int lli;

#define MAX_N 50005

lli N, M;
lli arr[MAX_N];

struct data {
  lli sum, lsum, rsum, msum;
};

data tree[4 * MAX_N];

#define lft_ch_ind(i) (2 * (i) + 1)
#define lft_ch(i) tree[lft_ch_ind(i)]
#define rht_ch_ind(i) (2 * (i) + 2)
#define rht_ch(i) tree[rht_ch_ind(i)]

void build_rec(lli i, lli l, lli r)
{
  if (l == r)
  {
    tree[i].sum = arr[l];
    tree[i].lsum = arr[l];
    tree[i].rsum = arr[l];
    tree[i].msum = arr[l];
  }
  else
  {
    lli m = (l + r) / 2;
    build_rec(lft_ch_ind(i), l, m);
    build_rec(rht_ch_ind(i), m + 1, r);
    
    tree[i].sum = lft_ch(i).sum + rht_ch(i).sum;
    tree[i].lsum = max(lft_ch(i).lsum, lft_ch(i).sum + rht_ch(i).lsum);
    tree[i].rsum = max(rht_ch(i).rsum, lft_ch(i).rsum + rht_ch(i).sum);
    tree[i].msum = max(max(lft_ch(i).msum, rht_ch(i).msum), lft_ch(i).rsum + rht_ch(i).lsum);
  }
}

void build()
{
  build_rec(0, 1, N);
}

data query_rec(lli i, lli l, lli r, lli x, lli y)
{
  data res;
  if (l == x and r == y) res = tree[i];
  else
  {
    lli m = (l + r) / 2;
    if (x <= m and y <= m) res = query_rec(lft_ch_ind(i), l, m, x, y);
    else if (m < x and m < y) res = query_rec(rht_ch_ind(i), m + 1, r, x, y);
    else
    {
      data left = query_rec(lft_ch_ind(i), l, m, x, m);
      data right = query_rec(rht_ch_ind(i), m + 1, r, m + 1, y);
      res.sum = left.sum + right.sum;
      res.lsum = max(left.lsum, left.sum + right.lsum);
      res.rsum = max(right.rsum, left.rsum + right.sum);
      res.msum = max(max(left.msum, right.msum), left.rsum + right.lsum);
    }
  }
  return res;
}

lli query(lli x, lli y)
{
  return query_rec(0, 1, N, x, y).msum;
}

int main(int argc, char const *argv[])
{
  scanf("%lld\n", &N);

  for (lli i = 1; i <= N; ++i)
    scanf("%lld ", &arr[i]);

  build();

  scanf("%lld\n", &M);
  
  lli x, y;
  for (lli i = 0; i < M; ++i)
    { scanf("%lld ", &x); scanf("%lld\n", &y); printf("%lld\n", query(x, y)); }
  
  return 0;
}