// Problem: Candys Candy
// 1464619  5791  Candy's Candy Accepted  C++11 0.029 2014-06-08 02:28:48
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3802

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int lli;

#define MAX_F 100000

lli F, C[MAX_F];

lli num_packings_for_pack_size(lli k)
{
  lli r = (C[0] % k) / (k / F);
  lli q = C[0] / k;
  for (int i = 1; i < F; ++i)
  {
    if ((C[i] % k) / (k / F) != r)
      return 0;
    
    q = min(C[i] / k, q);
  }
  return q - !r;
}

lli gcd(lli a, lli b)
{
  if (a < b) return gcd(b, a);
  lli temp;
  while (b != 0)
  {
    temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

int main(int argc, char const *argv[])
{
  while (true)
  {
    scanf("%lld\n", &F);
    if (F == 0) break;

    lli g = 0, sum = 0;
    for (int i = 0; i < F; ++i)
    {
      scanf("%lld", C + i);
      g = gcd(C[i], g);
      sum = sum + C[i];
    }
    scanf("\n");

    lli ans = 0;
    for (int n = 1; n * n < g + 1; ++n)
    {
      if (g % n != 0) continue;
      ans += num_packings_for_pack_size(n * F);
      if (n * n != g)
        ans += num_packings_for_pack_size(g / n * F);
    }
    printf("%lld\n", ans);
  }
  return 0;
}