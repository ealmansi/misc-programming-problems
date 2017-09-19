// http://www.spoj.com/problems/ABCDEF/
// 20182624    2017-09-19 21:40:25 ABCDEF  accepted edit    ideone it 1.83  16M CPP14
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int n;
vi s;
vi l;
vi::iterator it;

int solve() {

  l.reserve(n * n * n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        l.push_back(s[i] * s[j] + s[k]);
      }
    }
  }
  
  sort(l.begin(), l.end());

  int sol = 0;
  for (int i = 0; i < n; ++i) if (s[i] != 0) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        int val = s[i] * (s[j] + s[k]);
        sol += upper_bound(l.begin(), l.end(), val) - lower_bound(l.begin(), l.end(), val);
      }
    }
  }

  return sol;
}

int main(int argc, char const *argv[])
{
  cin >> n;
  s = vi(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  cout << solve() << endl;
  return 0;
}
