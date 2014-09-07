/*
12320314  2014-09-07 05:18:18 emilio  Garden Hull accepted   edit  run 0.00  2.8M   C++ 4.3.2
http://www.spoj.com/problems/GARDENHU/
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 10005

struct point {
  int x, y;
 
  bool operator <(const point &p) const
  {
    return x < p.x || (x == p.x && y < p.y);
  }
};
 
int ccw(const point &O, const point &A, const point &B)
{
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
int main(int argc, char const *argv[])
{
  int N;
  scanf("%d\n", &N);

  vector<point> ps(N), hll(2 * N);
  for (int i = 0; i < N; ++i)
    scanf("%d %d\n", &(ps[i].x), &(ps[i].y));

  sort(ps.begin(), ps.begin() + N);

  int k = 0;

  for (int i = 0; i < N; ++i)
  {
    while (k >= 2 && ccw(hll[k-2], hll[k-1], ps[i]) <= 0) --k;
    hll[k++] = ps[i];
  }

  for (int i = N - 2, t = k + 1; i >= 0; --i)
  {
    while (k >= t && ccw(hll[k-2], hll[k-1], ps[i]) <= 0) --k;
    hll[k++] = ps[i];
  }

  hll.resize(k);

  double ans = 0;
  for (int i = 0; i < k - 1; ++i)
    ans += sqrt(pow(hll[i+1].x - hll[i].x, 2) + pow(hll[i+1].y - hll[i].y, 2));
  ans += sqrt(pow(hll[0].x - hll[k-1].x, 2) + pow(hll[0].y - hll[k-1].y, 2));

  printf("%d\n", int(round(ans)));

  return 0;
}