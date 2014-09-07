// 1538039  5789  Army Buddies  Accepted  C++ 0.252 2014-09-07 03:00:22
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3800&mosmsg=Submission+received+with+ID+1538039

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef map<int, int> mii;

int S, B, L, R;

int main(int argc, char const *argv[])
{
  while (true)
  {
    scanf("%d %d", &S, &B);
    if (S == 0) break;

    mii is;
    mii::iterator it;
    int a, b;
    is[1] = S;
    for (int i = 0; i < B; ++i)
    {
      scanf("%d %d", &L, &R);
      it = is.upper_bound(L); --it;
      a = it->first, b = it->second;
      is.erase(it);

      if (a < L)
      {
        is[a] = L - 1;
      }
      if (R < b)
      {
        is[R + 1] = b;
      }

      if (not is.empty())
      {
        it = is.upper_bound(L);
        if (it != is.begin())
        {
          --it;
          printf("%d ", it->second);
          ++it;
        }
        else
        {
          printf("* ");
        }
        if (it != is.end())
          printf("%d\n", it->first);
        else
          printf("*\n");
      }
      else
      {
        printf("* *\n");
      }
    }
    printf("-\n");
  }
  return 0;
}