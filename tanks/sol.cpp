// Problem: Tanks
// 12320372 2014-09-07 05:35:28 emilio  Tanks accepted   edit  run 5.29  18M  C++ 4.3.2
// http://www.spoj.com/problems/TANKS/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int lli;
struct data {lli x, y, vx, vy;};

#define MAX_N 100

int n;
data d[MAX_N];
lli ts[2*MAX_N*MAX_N*MAX_N];

int max_num_colinear_points(lli t)
{
  double slope[MAX_N];
  int result = 0;
  for (int i = 0; i < n; ++i)
  {
    int partial_result = 0;
    int num_same_x = 0, num_diff_x = 0;
    for (int j = i + 1; j < n; ++j)
    {
      lli xi = d[i].x + d[i].vx * t, yi = d[i].y + d[i].vy * t;
      lli xj = d[j].x + d[j].vx * t, yj = d[j].y + d[j].vy * t;
      if (xi == xj)
      {
        ++num_same_x;
      }
      else
      {
        slope[num_diff_x] = double(yj - yi) / double(xj - xi);
        ++num_diff_x;
      }
    }
    partial_result = max(partial_result, num_same_x);

    sort(slope, slope + num_diff_x);
    int same_slope;
    for (int k = 0; k < num_diff_x; ++k)
    {
      if (k == 0 || slope[k - 1] != slope[k])
      {
        same_slope = 0;
      }
      ++same_slope;
      partial_result = max(partial_result, same_slope);
    }
    result = max(result, partial_result + 1);
  }
  return result;
}

int main(int argc, char const *argv[])
{
  while (true)
  {
    scanf ("%d", &n);
    if (n == 0) break;

    for (int i = 0; i < n; ++i)
      scanf ("%lld %lld %lld %lld", &d[i].x, &d[i].y, &d[i].vx, &d[i].vy);
    
    int num_ts = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        for (int k = j + 1; k < n; ++k)
        {
          lli a = d[i].vx * d[j].vy - d[i].vx * d[k].vy + d[j].vx * d[k].vy
                  - d[j].vx * d[i].vy + d[k].vx * d[i].vy - d[k].vx * d[j].vy;
          lli b = d[i].vx * d[j].y - d[i].vx * d[k].y + d[j].vx * d[k].y
                  - d[j].vx * d[i].y + d[k].vx * d[i].y - d[k].vx * d[j].y
                  + d[i].x * d[j].vy - d[i].x * d[k].vy + d[j].x * d[k].vy
                  - d[j].x * d[i].vy + d[k].x * d[i].vy - d[k].x * d[j].vy;
          lli c = d[i].x * d[j].y - d[i].x * d[k].y + d[j].x * d[k].y
                  - d[j].x * d[i].y + d[k].x * d[i].y - d[k].x * d[j].y;
          lli discr = b * b - 4 * a * c;
          if (discr >= 0)
          {
            double _a = double(a);
            double _b = double(b);
            double _c = double(c);
            double _discr = double(discr);

            double t1 = (- _b + sqrt(_discr)) / (2 * _a);
            double t2 = (- _b - sqrt(_discr)) / (2 * _a);
            if(t1 > -1e-5 and abs(t1 - round(t1)) < 1e-5)
            {
              ts[num_ts] = lli(round(t1)); ++num_ts;
            }
            if(t2 > -1e-5 and abs(t2 - round(t2)) < 1e-5)
            {
              ts[num_ts] = lli(round(t2)); ++num_ts;
            }
          }
        }
      }
    }

    ts[num_ts] = 0; ++num_ts;
    sort(ts, ts + num_ts);

    int result = 0;
    for (int i = 0; i < num_ts; ++i)
      if (i == 0 || ts[i - 1] != ts[i])
        result = max(result, max_num_colinear_points(ts[i]));

    printf("%d\n", result);
  }

  return 0;
}
