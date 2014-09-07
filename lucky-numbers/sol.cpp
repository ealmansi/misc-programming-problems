/*
1516691 4189  Lucky numbers Accepted  C++ 0.178 2014-08-11 05:20:24
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2190
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef queue<ll> qll;
typedef set<ll> sll;
#define rep(n) for (int __##__LINE__ = 0; __##__LINE__ < (n); ++__##__LINE__)
#define forr(i,d,h) for (int i = (d); i < (h); ++i)
#define forit(it, c) for (typeof (c).begin() it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()

#define MAX ((ll) 1e12)
ll T, A, B;
vll lnums;
sll _vlnums;

void bt(ll num, int pos)
{
  //cout << num << " " << pos << endl;
  forr(i, pos, lnums.size())
    if (lnums[i] <= MAX / num)
      _vlnums.insert(lnums[i] * num), bt(lnums[i] * num, i);
    else break;
}

void init()
{
  lnums.push_back(4);
  lnums.push_back(7);
  forr(i, 0, lnums.size())
  {
    if (lnums[i] * 10 + 4 <= MAX) lnums.push_back(lnums[i] * 10 + 4);
    if (lnums[i] * 10 + 7 <= MAX) lnums.push_back(lnums[i] * 10 + 7);
  }

  bt(1,0);
}

int main(int argc, char const *argv[])
{
  init();
  vll vlnums(all(_vlnums));

  cin >> T;
  rep(T)
  {
    cin >> A >> B;
    cout << distance(lower_bound(all(vlnums), A), upper_bound(all(vlnums), B)) << endl;
  }
  return 0;
}