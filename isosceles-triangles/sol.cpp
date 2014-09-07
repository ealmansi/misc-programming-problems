// 1530688  4480  Isosceles Triangles Accepted  C++ 1.589 2014-08-30 23:28:06
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2481

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define EPS (1e-10)
bool equal(double a, double b) { return abs(a - b) < EPS; }
#define iter(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 1005
int N;
int x[MAXN], y[MAXN];
double dist[MAXN][MAXN];

double calc_dist(int i, int j)
{
  double dx = x[i] - x[j], dy = y[i] - y[j];
  return sqrt(dx * dx + dy * dy);
}

int main(int argc, char const *argv[])
{
  cin >> N;
  while (N != 0)
  {
    iter(i, 0, N) cin >> x[i] >> y[i];
    iter(i, 0, N) iter(j, i, N) dist[i][j] = dist[j][i] = calc_dist(i, j);
    iter(i, 0, N) sort(dist[i], dist[i] + N);
    
    int ans = 0;
    iter(i, 0, N)
    {
      int j = 0, k;
      while (j < N)
      {
        k = j + 1;
        while (k < N and equal(dist[i][j], dist[i][k])) ++k;
        ans += ((k - j) * (k - j - 1)) / 2;
        j = k;
      }
    }

    cout << ans << endl;

    cin >> N;
  }
  return 0;
}