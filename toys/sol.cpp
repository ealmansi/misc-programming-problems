// Problem: Toys
// http://poj.org/problem?id=2318
// 13770014	ealmansi	2318	Accepted	212K	1016MS	C++	1398B	2015-01-09 04:51:30
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> pii;
#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define mp make_pair
#define fst first
#define snd second

#define MAXN 5005
#define MAXM 5005

int n, m, x1, y1, x2, y2;
int U[MAXN + 2], L[MAXN + 2];
pii T[MAXM];

int ccw(int x1, int y1, int x2, int y2)
{
 	return x1 * y2 - y1 * x2;
}

bool inside_bin(int i, int j)
{
	pii V[4] = {mp(L[i] - T[j].fst, y1 - T[j].snd),
				mp(U[i] - T[j].fst, y2 - T[j].snd),
				mp(U[i + 1] - T[j].fst, y2 - T[j].snd),
				mp(L[i + 1] - T[j].fst, y1 - T[j].snd)};
	forr(k, 0, 4) {
		int nk = (k + 1) % 4;
		if (ccw(V[k].fst, V[k].snd, V[nk].fst - V[k].fst, V[nk].snd - V[k].snd) < 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	bool printed = false;
	while (scanf("%d %d %d %d %d %d\n", &n, &m, &x1, &y1, &x2, &y2), n != 0) {
		if (printed) printf("\n");
		printed = true;
		U[0] = L[0] = x1;
		U[n + 1] = L[n + 1] = x2;
		forr(i, 1, n + 1) scanf("%d %d\n", &L[i], &U[i]);
		forr(i, 0, m) scanf("%d %d\n", &T[i].fst, &T[i].snd);
		sort(T, T + m);
		forr(i, 0, n + 1) {
			int count = 0;
			forr(j, 0, m) {
				if (max(L[i + 1], U[i + 1]) < T[j].fst) break;
				if (inside_bin(i, j)) ++count;
			}
			printf("%d: %d\n", i, count);
		}
	}
	return 0;
}