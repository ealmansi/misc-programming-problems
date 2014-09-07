/*
7303089  2014-08-01 04:51:42  apaapa   45D - Event Dates   GNU C++  Accepted   30 ms   0 KB
http://codeforces.com/problemset/problem/45/D
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define forr(i,d,h) for (int i = (d); i < (h); ++i)
#define repeat(n) forr(___, 0, n)

struct data {
  data() {}
  data(int i, int l, int r) : i(i), l(l), r(r) {}
  int i, l, r, val;
};

bool comp1(const data& a, const data& b)
{
  if (a.l != b.l) return a.l < b.l;
  else return a.r - a.l + 1 < b.r - b.l + 1;
}

bool comp2(const data& a, const data& b)
{
  return a.i < b.i;
}

int n;
data is[105];

int main(int argc, char const *argv[])
{
  cin >> n;
  forr(i, 0, n)
  {
    int l, r;
    cin >> l >> r;
    is[i] = data(i, l, r);
  }
  repeat(n)
  {
    sort(is, is + n, comp1);
    is[0].val = is[0].l;
    forr (i, 1, n) if (is[0].l != is[i].l) break; else ++(is[i].l);
    is[0].l = 100000000;
  }
  sort(is, is + n, comp2);
  forr(i, 0, n) cout << is[i].val << ((i + 1 < n) ? " " : "\n");

  return 0;
}