// 20277319  2017-10-02 19:15:12 emilio  Princess Farida accepted edit    ideone it 0.14  16M CPP14
// http://www.spoj.com/problems/FARIDA/

#include <iostream>
#include <vector>
using namespace std;

#define rg(i, f, t) for (int i = f; i < t; ++i)

using vi =  vector<int>;
using lli = long long int;

int T;
int N;
vi a(10005);

lli solve() {
  lli r1 = 0, r2 = 0;
  rg(i, 0, N) {
    int j = N - 1 - i;
    lli t = max(a[j] + r2, r1);
    r2 = r1;
    r1 = t;
  }
  return r1;
}

int main(int argc, char const *argv[])
{
  cin >> T;
  rg(t, 0, T) {
    cin >> N;
    rg(i, 0, N) {
      cin >> a[i];
    }
    cout << "Case " << (t + 1) << ": " << solve() << endl;
  }
  return 0;
}
