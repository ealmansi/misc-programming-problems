// http://www.spoj.com/problems/MKTHNUM/
// 20336760  2017-10-10 21:27:28 emilio  K-th Number accepted edit    ideone it 0.79  78M CPP14

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

#define rg(i, f, t) for (int i = f; i < t; ++i)

struct node;

using np = node *;

struct node
{
  node(np left, np right, int value) : left(left), right(right), value(value) {}
  np left, right;
  int value;
};

const int MAX_N = 100005;

int N, M;
int A[MAX_N], B[MAX_N], C[MAX_N];
np TS[MAX_N + 1];
int L, R, K;

np zero_tree(int sz)
{
  if (sz == 1) return new node(0, 0, 0);
  return new node(zero_tree(sz / 2), zero_tree((sz + 1) / 2), 0);
}

np update_tree(int i, int j, np n, int pos)
{
  if (j - i == 1) return new node(0, 0, n->value + 1);
  int m = (i + j) / 2;
  if (pos < m)
  {
    return new node(update_tree(i, m, n->left, pos), n->right, n->value + 1);
  }
  else
  {
    return new node(n->left, update_tree(m, j, n->right, pos), n->value + 1);
  }
}

int _query(int i, int j, np l, np r, int k)
{
  if (j - i == 1) return i;
  int m = (i + j) / 2;
  int t = r->left->value - l->left->value;
  if (k > t)
  {
    return _query(m, j, l->right, r->right, k - t);
  }
  else
  {
    return _query(i, m, l->left, r->left, k);
  }
}

bool B_comp(int i, int j)
{
  return A[i] < A[j] || A[i] == A[j] && i < j;
}

bool C_comp(int i, int j)
{
  return B[i] < B[j] || B[i] == B[j] && i < j;
}

void init()
{
  rg(i, 0, N) B[i] = i, C[i] = i;
  sort(B, B + N, B_comp);
  sort(C, C + N, C_comp);
  TS[0] = zero_tree(N);
  rg(i, 0, N) TS[i + 1] = update_tree(0, N, TS[i], C[i]);
}

int query()
{
  return A[B[_query(0, N, TS[L - 1], TS[R], K)]];
}

int main()
{
  scanf("%d %d\n", &N, &M);
  rg(i, 0, N) scanf("%d", &A[i]);
  init();
  rg(i, 0, M)
  {
    scanf("%d %d %d\n", &L, &R, &K);
    printf("%d\n", query());
  }
  return 0;
}
