#include <stdio.h>
#include <iostream>
#include <vector>
// 12325573	2014-09-08 00:21:36	emilio	Evaluate the polynomial	accepted	 edit  run	1.31	2.8M	 C++ 4.3.2
// http://www.spoj.com/problems/POLEVAL/

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int t = 0, n, k;
vi c, x;

void solve()
{
	++t;
	cout << "Case " << t << ":" << endl;
	for (int i = 0; i < x.size(); ++i)
	{
		ll res = c[n];
		for (int j = n - 1; j >= 0; --j)
			res = res * x[i] + c[j];
		cout << res << endl;
	}
}

int main(int argc, char const *argv[])
{
	while (true)
	{
		cin >> n;
		if (n == -1) break;
		
		c.resize(n + 1);
		for (int i = n; i >= 0; --i)
			cin >> c[i];

		cin >> k;
		x.resize(k);
		for (int i = 0; i < k; ++i)
			cin >> x[i];

		solve();
	}
	
	return 0;
}