// Problem: Drainage Ditches
// http://poj.org/problem?id=1273
// 13762352	ealmansi	1273	Accepted	376K	16MS	C++	1030B	2015-01-05 14:33:27
#include <cstdio>
#include <queue>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 205
#define MAXM 205

int n, m;
int s, e, c;
int C[MAXM][MAXM];
int P[MAXM], I[MAXM];

int bfs()
{
	P[0] = 0; forr(i, 1, m) P[i] = -1;
	I[0] = 1e9; forr(i, 1, m) I[i] = 0;
	queue<int> Q; Q.push(0);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		forr(v, 0, m) if (P[v] == -1 && C[u][v] > 0) {
			P[v] = u;
			I[v] = min(I[u], C[u][v]);
			if (v == m - 1) return I[v];
			Q.push(v);
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	while (scanf("%d %d\n", &n, &m) != EOF) {
		forr(i, 0, m) forr(j, 0, m) C[i][j] = 0;
		forr(i, 0, n) scanf("%d %d %d\n", &s, &e, &c), --s, --e, C[s][e] += c;
		int ans = 0;
		while (true) {
			int inc = bfs();
			if (inc == 0) break;
			ans += inc;
			int u, v = m - 1;
			while (v != 0) {
				u = P[v];
				C[u][v] -= inc;
				C[v][u] += inc;
				v = u;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}