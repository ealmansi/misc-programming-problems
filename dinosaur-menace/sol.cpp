// Problem: Dinosaur Menace
/*
12062919   2014-08-01 02:05:21  emilio  Dinosaur Menace  accepted  edit  run 3.45   11M   C++ 4.3.2
http://www.spoj.com/problems/DINOSM/
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define fr(i,d,h) for (int i = d; i < h; ++i)

#define MAXN 305
#define MAXW 1000005
#define MAXH 1000005

int N, W, H;
int x[MAXW], y[MAXH];
double dist[MAXN+2][MAXN+2];

double calc_dist(int i, int j)
{
  return sqrt((1.0*x[i]-x[j])*(1.0*x[i]-x[j])
      + (1.0*y[i]-y[j])*(1.0*y[i]-y[j]));
}

void init_dist()
{
  fr (i, 0, N) fr (j, 0, N) dist[i][j] = dist[j][i] = calc_dist(i, j);
  fr (i, 0, N) dist[i][N] = dist[N][i] = 2 * min(x[i], H - y[i]);
  fr (i, 0, N) dist[i][N+1] = dist[N+1][i] = 2 * min(y[i], W - x[i]);
  dist[N][N+1] = dist[N+1][N] = max(MAXW, MAXH);
}

int stk[MAXN+2], sz;
bool visitado[MAXN+2];

bool f(double t)
{
  sz = 0;
  fill(visitado, visitado + N + 2, false);

  stk[sz++] = N;
  visitado[N] = true;

  while (sz > 0)
  {
    int i = stk[--sz];
    if (i == N + 1) return false;
    fr (j, 0, N + 2) if (not visitado[j] and dist[i][j] <= 2 * t)
    {
      stk[sz++] = j;
      visitado[j] = true;
    }
  }

  return true;
}

int main(int argc, char const *argv[])
{
  while (scanf("%d %d %d\n", &N, &W, &H), N != -1)
  {
    fr (i, 0, N) scanf("%d %d\n", &x[i], &y[i]);

    init_dist();
    double low = 1e-5, mid, high = min(W, H);
    while (high - low > 1e-5)
    {
      mid = (high + low) / 2;
      if (f(mid)) low = mid;
      else high = mid;
    }
    printf("%.3f\n", mid);
  }
  return 0;
}