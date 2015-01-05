// Problem: Another Crisis
// 1530701 4472  Another Crisis  Accepted  C++ 0.222 2014-08-30 23:57:59
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2473

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
typedef vector<int> vi;

#define iter(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 100005
int N, T;
vi ps[MAXN];

int f(int i)
{
  if (ps[i].size() == 0) return 1;

  vi vs;
  for (vi::iterator it = ps[i].begin(); it != ps[i].end(); ++it)
    vs.push_back(f(*it));

  int req = ceil(T * ps[i].size() / 100.0);
  nth_element(vs.begin(), vs.begin() + req, vs.end());
  int ans = accumulate(vs.begin(), vs.begin() + req, 0);
  return ans;
}

int main(int argc, char const *argv[])
{
  int boss;
  cin >> N >> T;
  while (N != 0)
  {
    iter(i, 0, N + 1) ps[i].clear();

    iter(i, 1, N + 1) cin >> boss, ps[boss].push_back(i);

    cout << f(0) << endl;

    cin >> N >> T;
  }
  return 0;
}