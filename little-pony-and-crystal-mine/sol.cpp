// Problem: Little Pony And Crystal Mine
// 7354841 	Practice: apaapa 	454A - 8 	GNU C++ 	Accepted 	15 ms 	4 KB 	2014-08-05 21:13:31 	2014-08-05 21:13:31
// http://codeforces.com/problemset/problem/454/A

#include <iostream>
using namespace std;

int n;
int main() {
	cin >> n;
	for (int i = 0; i < n/2; i++)
	{
		for (int j = 0; j < n/2 - i; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "D";
		}
		for (int j = 0; j < n/2 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "D";
	}
	cout << endl;
	for (int i = n/2 - 1; i >= 0; i--)
	{
		for (int j = 0; j < n/2 - i; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "D";
		}
		for (int j = 0; j < n/2 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}
