// 7698096 2014-09-07 07:13:07 apaapa  161B - Discounts  GNU C++ Accepted  30 ms 200 KB
// http://codeforces.com/problemset/problem/161/B

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
typedef list<int> li;
#define mp make_pair

#define forr(i,d,h) for (int i = (d); i < (h); ++i)

#define MAXN 105
#define MAXK 105
int n, k;
vector<pair<int, pair<int, int> > > items;
vector<list<int> > carts;

int main(int argc, char const *argv[])
{
  int c, t, min_stool_c = 1100000000, min_pencil_c = 1100000000;
  double value;

  cin >> n >> k;
  items.resize(n);
  carts.resize(k);
  forr(i, 0, n)
  {
    cin >> c >> t;
    items[i] = mp(t, mp(-c, i + 1));
    if (t == 1) min_stool_c = min(min_stool_c, c);
    else if (t == 2) min_pencil_c = min(min_pencil_c, c);
  }
  sort(items.begin(), items.end());

  value = 0.0;
  forr(i, 0, k - 1)
  {
    if (items[i].first == 1)
      value += items[i].second.first / 2.0;
    else
      value += items[i].second.first;
    carts[i].push_back(items[i].second.second);
  }
  forr(i, k - 1, n)
  {
    value += items[i].second.first;
    carts[k - 1].push_back(items[i].second.second);
  }
  if (items[k-1].first == 1)
    value += min(min_stool_c, min_pencil_c) / 2.0;

  printf("%.1f\n", -value);
  forr(i, 0, k)
  {
    li::iterator it;
    cout << carts[i].size() << " ";
    for (it = carts[i].begin(); it != --(carts[i].end()); ++it)
      cout << *it << " ";
    cout << *it << endl;
  }

  return 0;
}