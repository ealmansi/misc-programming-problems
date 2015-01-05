// Problem: Crane Balancing
// 517194 00:39:15  Crane Balancing Accepted  0.00 s  C++
// https://icpc.kattis.com/problems/crane

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_N 105
#define MIN_X (-2000)
#define MAX_X 2000

int N;
double l_x, r_x, w_x;
double x[MAX_N], y[MAX_N];

int main(int argc, char const *argv[])
{
  scanf("%d\n", &N);

  l_x = 1e10; r_x = -1e10;
  for (int i = 0; i < N; ++i)
  {
    scanf("%lf %lf\n", &x[i], &y[i]); x[i] -= MIN_X;
    if (y[i] == 0)
    {
      l_x = min(l_x, x[i]);
      r_x = max(r_x, x[i]);
    }
  }
  w_x = x[N] = x[0]; y[N] = y[0];

  double area = 0, c_x = 0, temp;
  for (int i = 0; i < N; ++i)
  {
    temp = x[i] * y[i+1] - x[i+1] * y[i];
    area += temp;
    c_x += temp * (x[i] + x[i+1]);
  }
  area /= 2;
  c_x /= (6 * area);
  area = abs(area);

  double W_min = 0, W_max = 1e100;

  // ineq 1
  if (w_x < l_x)
  {
    W_max = min(W_max, area * (c_x - l_x) / (l_x - w_x));
  }
  else if (w_x == l_x)
  {
    if (c_x < l_x)
    {
      printf("unstable\n");
      return 0;
    }
  }
  else if (w_x > l_x)
  {
    W_min = max(W_min, area * (c_x - l_x) / (l_x - w_x));
  }

  // ineq 2
  if (w_x < r_x)
  {
    W_min = max(W_min, area * (r_x - c_x) / (w_x - r_x));
  }
  else if (w_x == r_x)
  {
    if (c_x > r_x)
    {
      printf("unstable\n");
      return 0;
    }
  }
  else if (w_x > r_x)
  {
    W_max = min(W_max, area * (r_x - c_x) / (w_x - r_x));
  }

  if (W_max < W_min)
  {
    printf("unstable\n");
    return 0;
  }
  else if (W_max == 1e100)
  {
    printf("%d .. inf\n", int(floor(W_min)));
    return 0;
  }
  else
  {
    printf("%d .. %d\n", int(floor(W_min)), int(ceil(W_max)));
    return 0;
  }

  return 0;
}