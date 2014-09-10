// 7355622 	Practice: apaapa 	342B - 21 	GNU C++ 	Accepted 	404 ms 	1180 KB 	2014-08-05 23:33:21 	2014-08-05 23:33:21
// http://codeforces.com/problemset/problem/342/B

#include <iostream>
#include <cmath>
using namespace std;

#define MAXM 100005
#define MAXT 1000000005

int n, m, s, f;
int t[MAXM], l[MAXM], r[MAXM];

int main()
{
	cin >> n >> m >> s >> f;
	for (int i = 0; i < m; i++)
		cin >> t[i] >> l[i] >> r[i];
	
	int direc;
	char letra;
	if (s < f)
	{
		direc = 1;
		letra = 'R';
	}
	else
	{
		direc = -1;
		letra = 'L';
	}
	
	int step = 1, pos = s;
	for (int i = 0; i < m; i++)
	{
		//cout << step << " " << t[i] << endl;
		while (step < t[i])
		{
			cout << letra; pos += direc;
			if (pos == f) {cout << endl; return 0;}
			++step;
		}
		
		if ((l[i] <= pos and pos <= r[i]) or (l[i] <= (pos+direc) and (pos+direc) <= r[i]))
		{
			cout << 'X';
			++step;
		}
		else
		{
			cout << letra; pos += direc;
			if (pos == f) {cout << endl; return 0;}
			++step;
		}
	}
	while (pos != f)
	{
		cout << letra; pos += direc;
		if (pos == f) {cout << endl; return 0;}
		++step;
	}
	
	return 0;
}
