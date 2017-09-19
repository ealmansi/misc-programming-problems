// http://www.spoj.com/problems/ABA12C/
// 20182110   2017-09-19 19:50:54 Buying Apples!  accepted edit    ideone it 0.00  16M CPP14
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1e6;

int c;
int n, k;
vi y;
vvi dp;

int solve() {
  dp = vvi(n + 1, vi(k + 1, inf));
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      int val = inf;
      for (int t = 0; t < j; ++t) if (y[t] != -1) {
        val = min(val, dp[i - 1][j - t - 1] + y[t]);
      }
      dp[i][j] = val;
    }
  }
  return dp[n][k] != inf ? dp[n][k] : -1;
}

int main(int argc, char const *argv[])
{
  cin >> c;
  for (int _ = 0; _ < c; ++_) {
    cin >> n >> k;
    y = vi(k);
    for (int i = 0; i < k; ++i) {
      cin >> y[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
