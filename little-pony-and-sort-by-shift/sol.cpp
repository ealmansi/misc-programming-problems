// Problem: Little Pony And Sort By Shift
// 7354963 	Practice: apaapa 	454B - 58 	GNU C++ 	Accepted 	62 ms 	400 KB 	2014-08-05 21:32:08 	2014-08-05 21:32:08
// http://codeforces.com/problemset/problem/454/B

#include <iostream>
#include <fstream>
using namespace std;

int n;
int a[100005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ind = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[(i+1)%n])
			if (ind == -1) ind = i;
			else {cout << -1 << endl; return 0;}
	}
	cout << ((n - ind - 1)%n) << endl;
	
	return 0;
}
