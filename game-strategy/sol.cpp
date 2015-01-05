// Problem: Game Strategy
// 524818 05:16:15  Game Strategy Accepted  2.51 s  C++
// https://icpc.kattis.com/problems/game

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAX_N 30
#define MAX_OPTS 1000005

int N;
vi opts(MAX_OPTS, -1);
vi from(MAX_N, -1);
vi to(MAX_N, -1);

vi reachable(MAX_N, -1);
vi _reachable(MAX_N, -1);

vvi ans(MAX_N, vi(MAX_N, -1));

int main(int argc, char const *argv[])
{
  int num_opts, opt_index = 0, temp;
  char buffer[MAX_N];

  scanf("%d\n", &N);
  for (int i = 0; i < N; ++i)
  {
    from[i] = opt_index;
    scanf("%d ", &num_opts);
    for (int j = 0; j < num_opts; ++j)
    {
      scanf("%s ", buffer);
      temp = 0;
      for (int k = 0; buffer[k] != '\0'; ++k)
        temp |= 1 << (buffer[k] - 'a');
      opts[opt_index] = temp;
      ++opt_index;
    }
    to[i] = opt_index;
  }

  // inicializo reachable y ans
  for (int i = 0; i < N; ++i)
  {
    reachable[i] = (1 << i);
    ans[i][i] = 0;
  }

  // repetir n veces
  for (int k = 1; k < N + 1; ++k)
  {
    // copio reachable
    for (int i = 0; i < N; ++i)
      _reachable[i] = reachable[i];

    // para cada letra i
    for (int i = 0; i < N; ++i)
    {
      // para cada opcion de la letra i
      for (int j = from[i]; j < to[i]; ++j)
      {
        temp = -1;
        for (int l = 0; l < N; ++l)
          if ((opts[j] & (1 << l)) != 0)
            temp &= reachable[l];
        _reachable[i] |= temp;
      }
    }

    // actualizo reachable y ans
    for (int i = 0; i < N; ++i)
    {
      reachable[i] = _reachable[i];
      for (int l = 0; l < N; ++l)
        if ((reachable[i] & (1 << l)) != 0 and ans[i][l] == -1)
          ans[i][l] = k;
    }
  }

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      printf("%d", ans[i][j]);
      if (j + 1 < N)
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}
