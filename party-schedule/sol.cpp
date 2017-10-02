// http://www.spoj.com/problems/PARTY/
// 20278035  2017-10-02 21:15:28 emilio  Party Schedule  accepted edit    ideone it 0.00  16M CPP14

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

#define rg(i, f, t) for (int i = f; i < t; ++i)

const int MAX_B = 505;
const int MAX_N = 105;

int B, N;
vi c(MAX_N), f(MAX_N);

void solve()
{
  vii dp(N + 1, vi(B + 1));
  rg(b, 0, B + 1)
  {
    dp[0][b] = 0;
  }
  rg(i, 1, N + 1) rg(b, 0, B + 1)
  {
    int best = dp[i - 1][b];
    if (c[i - 1] <= b)
    {
      best = max(best, dp[i - 1][b - c[i - 1]] + f[i - 1]);
    }
    dp[i][b] = best;
  }
  int best_f = dp[N][0], best_b = 0;
  rg(b, 0, B + 1)
  {
    if (dp[N][b] > best_f)
    {
      best_f = dp[N][b], best_b = b;
    }
  }
  cout << best_b << " " << best_f << endl;
}

int main(int argc, char const *argv[])
{
  while (true)
  {
    cin >> B >> N;
    if (B == 0 && N == 0)
    {
      return 0;
    }
    for (int i = 0; i < N; ++i)
    {
      cin >> c[i] >> f[i];
    }
    solve();
  }
}
