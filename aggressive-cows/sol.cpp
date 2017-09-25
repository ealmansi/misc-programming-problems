//http://www.spoj.com/problems/AGGRCOW/
//20216546  2017-09-25 03:42:53 emilio  Aggressive cows accepted edit    ideone it 0.06  16M CPP14
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define rg(i, f, t) for(int i = f; i < t; ++i)

int T, N, C;
vi x;

bool check(int d) {
  int i = 0, c = C - 1;
  while (c > 0) {
    int j = i + 1;
    while (j < N && x[j] - x[i] < d) { ++j; }
    if (j == N) {
      return false;
    }
    i = j;
    --c;
  }
  return true;
}

int solve() {
  sort(x.begin(), x.end());
  int lo = 0, mid = -1, hi = x[N - 1] - x[0] + 1;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main()
{
  cin >> T;
  rg(t, 0, T) {
    cin >> N >> C;
    x = vi(N);
    rg(i, 0, N) {
      cin >> x[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
