// Problem: Ball Stacking
// 1465557 5790  Ball Stacking Accepted  C++11 0.566 2014-06-10 02:21:36
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3801

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;

#define MAX_ROWS 1000

lli rows, N;
lli balls[(MAX_ROWS / 2) * (MAX_ROWS + 1)];
lli opt_mem[(MAX_ROWS / 2) * (MAX_ROWS + 1)];

inline lli tn(lli n)
{
  if (n % 2 == 0) return (n / 2) * (n + 1);
  else return ((n + 1) / 2) * n;
}

lli opt(lli i, lli j)
{
  if (j < 0) return 0;
  else if (rows - 1 < i) return 0;
  else if (rows - 1 - i < j) return opt(i, rows - 1 - i);
  else
  {
    if (opt_mem[tn(i + j) + j] != -1)
      return opt_mem[tn(i + j) + j];
    
    lli opt_ij = 0;
    for (int k = 0; k < j + 1; ++k)
      opt_ij += balls[tn(i + k) + k];
    opt_ij += opt(i + 1, j);

    opt_ij = max(opt_ij, opt(i, j - 1));
    opt_ij = max(opt_ij, lli(0));

    opt_mem[tn(i + j) + j] = opt_ij;
    return opt_mem[tn(i + j) + j];
  }
}

int main(int argc, char const *argv[])
{
  while (true)
  {
    scanf("%lld\n", &rows);
    if (rows == 0) break;

    N = tn(rows);

    fill(balls, balls + N, 0);
    fill(opt_mem, opt_mem + N, -1);

    for (int n = 0; n < N; ++n)
      scanf("%lld", balls + n);

    printf("%lld\n", opt(0, rows - 1));
  }

  return 0;
}