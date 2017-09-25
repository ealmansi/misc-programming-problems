// http://www.spoj.com/problems/INVCNT/
// 20224625  2017-09-25 23:15:38 emilio  Inversion Count accepted edit    ideone it 0.12  15M CPP14
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using lli = long long int;

#define rg(i, f, t) for (int i = f; i < t; ++i)

static const int MAXN = 200005;

int T, N;
vi a(MAXN), t(MAXN);

lli _solve(int l, int r) {
  if (r - l < 2) {
    return 0;
  }
  int mid = (l + r) / 2;
  lli ans = _solve(l, mid) + _solve(mid, r);
  int i, j, k;
  i = l; j = mid; k = 0;
  while (i < mid || j < r) {
    if (j == r || i < mid && a[i] <= a[j]) {
      t[k] = a[i]; k++; i++;
    } else {
      t[k] = a[j]; k++; j++;
      ans += mid - i;
    }
  }
  rg(q, 0, k) {
    a[l + q] = t[q];
  }
  return ans;
}

lli solve() {
  return _solve(0, N);
}

int main() {
  cin >> T;
  rg(t, 0, T) {
    cin >> N;
    rg(i, 0, N) {
      cin >> a[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
