// Problem: Little Pony And Expected Maximum
// 7355477 	Practice: apaapa 	453A - 35 	GNU C++ 	Accepted 	62 ms 	4 KB 	2014-08-05 23:00:26 	2014-08-05 23:00:26
// http://codeforces.com/problemset/problem/453/A

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

int nn, mm;
long double n, m;
int main () {
	cin >> mm >> nn;
	n = 1.0 * nn; m = 1.0 * mm;
	
	long double res = 0;
	for (int ii = 1; ii <=m; ii++)
	{
		long double i = 1.0 * ii;
		res += i * (pow(i / m, n) - pow((i - 1) / m, n));
	}
	cout.precision(10);
	cout << res << endl;
	
	return 0;
}
