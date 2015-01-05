// Problem: Stock Exchange
// 1540951 	4183 	Stock Exchange 	Accepted 	C++ 	0.059 	2014-09-10 21:06:03
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=2184

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define forn(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long int ll;
#define INF ((ll)1e18)

#define MAXN 100005

ll v[MAXN];
ll mv[MAXN];
ll l[MAXN];

int lis(int n)
{
	forn(i,n) mv[i] = INF;
	mv[0] = -INF;
	int res = 0;
	forn(i, n)
	{
		int me = lower_bound(mv, mv + n, v[i]) - mv;
		mv[me] = v[i];
		if (me>res) res = me;
	}
	return res;
}

int L;

int main(){

	while (cin >> L)
	{
		forn(i,L) cin >> v[i];
		cout << lis(L) << endl;
	}
	return 0;
}
