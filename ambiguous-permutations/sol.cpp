// Problem: Ambiguous Permutations
// http://www.spoj.com/problems/PERMUT2/
// 13667711 2015-02-15 04:22:12 emilio  Ambiguous Permutations  accepted   edit  run 0.22  3.4M   C++ 4.9
#include <iostream>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 100005

int N;
int perm[MAXN];

int main(int argc, char const *argv[])
{
  while (cin >> N, N > 0) {
    forr (i, 0, N) cin >> perm[i], --perm[i];
    bool ambiguous = true;
    forr (i, 0, N) if (perm[perm[i]] != i) {
      ambiguous = false;
      break;
    }
    if (ambiguous) {
      cout << "ambiguous" << endl;
    }
    else {
      cout << "not ambiguous" << endl; 
    }
  }
  return 0;
}