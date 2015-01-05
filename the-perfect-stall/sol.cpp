// Problem: The Perfect Stall
// http://poj.org/problem?id=1274
// 13763855	ealmansi	1274	Accepted	944K	266MS	C++	1294B	2015-01-06 04:52:50

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 205
#define MAXM 205

int n, m;
int s, t;
int C[2 + MAXN + MAXM][2 + MAXN + MAXM];
int P[2 + MAXN + MAXM], I[2 + MAXN + MAXM];

int bfs()
{
	forr(i, 0, 2 + n + m) P[i] = -1, I[i] = 0;
	P[s] = s, I[s] = 1e9;
	queue<int> Q; Q.push(s);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		forr(v, 0, 2 + n + m) if (P[v] == -1 && C[u][v] > 0) {
			P[v] = u;
			I[v] = min(I[u], C[u][v]);
			if (v == t) return I[v];
			Q.push(v);
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	while (cin >> n) {
		cin >> m;
		s = 0, t = 1 + n + m;
		forr(i, 0, 2 + n + m) forr(j, 0, 2 + n + m) C[i][j] = 0;
		forr(i, 0, n) C[s][1 + i] = 1;
		forr(i, 0, m) C[1 + n + i][t] = 1;
		forr(i, 0, n) {
			int k, si;
			cin >> k;
			forr(j, 0, k) cin >> si, --si, C[1 + i][1 + n + si] = 1;
		}
		int inc, ans = 0;
		while (inc = bfs(), inc > 0) {
			ans += inc;
			int u, v = t;
			while (v != s) {
				u = P[v];
				C[u][v] -= inc;
				C[v][u] += inc;
				v = u;
			}
		}
		cout << ans << endl;
	}
	return 0;
}