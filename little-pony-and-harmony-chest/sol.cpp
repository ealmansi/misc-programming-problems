// Problem: Little Pony And Harmony Chest
// 7355864 	Practice: apaapa 	453B - 36 	GNU C++ 	Accepted 	2339 ms 	246580 KB 	2014-08-06 00:40:56 	2014-08-06 00:40:56
// http://codeforces.com/problemset/problem/453/B

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int a[105];
int dp[105][300000];
int averga[105][300000];

int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int pedazos[105];

int criba[61];

void init()
{	
	pedazos[n-1] = abs(a[n - 1] - 1);
	for (int i = n - 2; i >= 0; i--)
		pedazos[i] = abs(a[i] - 1) + pedazos[i+1];
	
	int cant_primos = 0;
	fill(criba, criba + 61, 0);
	criba[1] = 0;
	for (int i = 2; i < 61; i++)
	{
		if (criba[i] == 0)
		{
			criba[i] = 1<<cant_primos; ++cant_primos;
			for (int j = 2; i * j < 61; j++)
			{
				criba[i * j] = criba[i * j] | criba[i];
			}
		}
	}
}

int f(int i, int S)
{
	if(dp[i][S] == 0)
	{
		if (i == n) dp[i][S] = 0 + 1;
		else
		{
			int val = -1, res = 1000000000;
			for (int j = 1; j < 60; j++)
			{
				if ((criba[j] & S) == 0)
				{
					int candidato = abs(a[i] - j) + f(i + 1, criba[j] | S) - 1;
					if (candidato < res)
					{
						res = candidato;
						val = j;
					}
				}
			}
			averga[i][S] = val;
			dp[i][S] = res + 1;
		}
	}
	return dp[i][S];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init();
	f(0, 0);
	int S = 0;
	bool printed = false;
	for (int i = 0; i < n; i++)
	{
		int b = averga[i][S];
		S |= criba[b];
		if (printed) cout << " ";
		cout << b;
		printed = true;
	}
	cout << endl;
	return 0;
}
