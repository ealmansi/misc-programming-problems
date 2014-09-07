// 1538054  5798  Jupiter Atacks! Accepted  C++ 0.339 2014-09-07 03:25:02
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3809&mosmsg=Submission+received+with+ID+1538053

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int lli;

#define MAX_B 1000000000
#define MAX_P 1000000000
#define MAX_L 100000
#define MAX_N 100000

lli B, P, L, N, inv_B;
lli f[MAX_L + 1], tree[MAX_L + 1];
lli b_to_the[MAX_L + 1], inv_b_to_the[MAX_L + 1];

lli tree_read(lli i)
{
  lli v = 0;
  while (i > 0)
  {
    v = (v + tree[i]) % P;
    i = i - (i & -i);
  }
  return v;
}

void tree_add(lli i, lli v)
{
  while (i <= L + 1)
  {
    tree[i] = (tree[i] + v) % P;
    i = i + (i & -i);
  }
}

void comm_edit(lli i, lli v)
{
  v = (b_to_the[L - i] * v) % P;
  lli aux = f[i]; f[i] = v;
  tree_add(i, (v - aux) % P);
}

void comm_hash(lli i, lli j)
{
  lli hash = ((inv_b_to_the[L - j] * (tree_read(j) - tree_read(i - 1)) % P) % P + P) % P;
  printf("%lld\n", hash);
}

lli pow_mod(lli b, lli e, lli mod)
{
  lli res = 1;
  for (lli aux = b; e > 0; aux = (aux * aux) % mod, e = e / 2)
    if (e % 2 == 1)
      res = (res * aux) % mod;
  return res;
}

void init()
{
  fill(f, f + L + 1, 0);
  fill(tree, tree + L + 1, 0);

  inv_B = pow_mod(B, P - 2, P);
  
  b_to_the[0] = 1;
  for (int i = 1; i < L + 1; ++i)
    b_to_the[i] = (B * b_to_the[i - 1]) % P;
  
  inv_b_to_the[0] = 1;
  for (int i = 1; i < L + 1; ++i)
    inv_b_to_the[i] = (inv_B * inv_b_to_the[i - 1]) % P;
}

int main(int argc, char const *argv[])
{
  while (true)
  {
    scanf("%lld %lld %lld %lld\n", &B, &P, &L, &N);
    if (B == 0 and P == 0 and L == 0 and N == 0) break;

    init();

    char comm;
    lli op1, op2;
    for (int i = 0; i < N; ++i)
    {
      scanf("%c %lld %lld\n", &comm, &op1, &op2);
      switch(comm)
      {
      case 'E':
        comm_edit(op1, op2);
        break;
      case 'H':
        comm_hash(op1, op2);
        break;
      }
    }
    printf("-\n");
  }
  return 0;
}