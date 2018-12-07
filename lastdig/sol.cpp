// https://www.spoj.com/status/ns=22840694
// 22840694 	2018-12-07 21:40:52 	emilio	The last digit	accepted edit    ideone it 	0.00 	15M 	CPP14
#include <iostream>
using namespace std;

int solve (int a, int b) {
  int p = a, r = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      r = (r * p) % 10;
    }
    p = (p * p) % 10;
    b = b / 2;
  }
  return r;
}

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;
  }
  return 0;
}
