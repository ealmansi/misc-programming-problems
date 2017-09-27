// 20241286 2017-09-27 17:42:49 emilio  Edit distance accepted edit    ideone it 0.13  15M CPP14
// http://www.spoj.com/problems/EDIST/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define rg(i, f, t) for (int i = f; i < t; ++i)

int edit_distance(const string& a, const string& b)
{
  int n = a.size() + 1, m = b.size() + 1;
  vvi dp(n, vi(m));
  rg(j, 0, m) dp[0][j] = j;
  rg(i, 0, n) dp[i][0] = i;
  rg(i, 1, n) rg(j, 1, m)
  {
    if (a[i - 1] == b[j - 1])
    {
      dp[i][j] = dp[i - 1][j - 1];
    }
    else {
      dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
    }
  }
  return dp[n - 1][m - 1];
}

int main()
{
  int T;
  cin >> T;
  rg(t, 0, T)
  {
    string a, b;
    cin >> a >> b;
    cout << edit_distance(a, b) << endl;
  }
  return 0;
}
