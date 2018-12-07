// https://www.spoj.com/problems/PIGBANK/
// 22840814 	2018-12-07 22:30:04 	emilio	Piggy-Bank	accepted edit    ideone it 	0.07 	15M 	CPP14-CLANG

#define MAX_F 10002
#define MAX_N 502
#define MAX_P 50002
#define MAX_W 10002
#define INF (MAX_F * MAX_P)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

int T;
int E, F, D;
int N;
vi I;
vi P;
vi W;
vi M;

bool compare_coins (int i, int j) {
  return (
    W[i] < W[j] ||
    W[i] == W[j] && P[i] < P[j] ||
    W[i] == W[j] && P[i] == P[j] && i < j
  );
}

int _solve (int w) {
  if (M[w] == -1) {
    int ans = INF;
    for (int n = 0; n < N; ++n) {
      if (n == 0 || W[I[n - 1]] != W[I[n]]) {
        if (w < W[I[n]]) {
          break;
        }
        ans = min(ans, P[I[n]] + _solve(w - W[I[n]]));
      }
    }
    M[w] = ans;
  }
  return M[w];
}

int solve () {
  D = F - E;
  sort(I.begin(), I.end(), compare_coins);
  M.resize(D + 1);
  for (int w = 0; w <= D; ++w) {
    M[w] = -1;
  }
  M[0] = 0;
  return _solve(D);
}

int main () {
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> E >> F;
    cin >> N;
    I.resize(N);
    P.resize(N);
    W.resize(N);
    for (int n = 0; n < N; ++n) {
      I[n] = n;
      cin >> P[n] >> W[n];
    }
    int ans = solve();
    if (ans == INF) {
      cout << "This is impossible." << endl;
    } else {
      cout << "The minimum amount of money in the piggy-bank is " << ans << "." << endl;
    }
  }
  return 0;  
}
