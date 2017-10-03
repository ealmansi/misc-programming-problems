// http://www.spoj.com/problems/TRT/
// 20284539  2017-10-03 19:42:52 emilio  Treats for the Cows accepted edit    ideone it 0.01  33M CPP14

#include <iostream>
#include <vector>
using namespace std;

#define rg(i, f, t) for (int i = f; i < t; ++i)

using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvlli = vector<vlli>;

const int MAX_N = 2005;

int N;
vi a(MAX_N);

lli solve()
{
  vvlli dp(N, vlli(N));

  rg(i, 0, N) dp[i][i] = N * a[i];
  rg(k, 1, N) rg(i, 0, N - k)
  {
    lli A = N - k;
    dp[i][i + k] =
        max(
            A * a[i] + dp[i + 1][i + k],
            A * a[i + k] + dp[i][i + k - 1]);
  }
  return dp[0][N - 1];
}

int main()
{
  cin >> N;
  rg(i, 0, N)
  {
    cin >> a[i];
  }
  cout << solve() << endl;
  return 0;
}
