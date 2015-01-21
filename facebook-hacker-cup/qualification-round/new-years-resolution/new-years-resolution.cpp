#include <cstdio>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 25
#define MAXQ 1005
int T, N;
int GP, GC, GF;
int P[MAXN], C[MAXN], F[MAXN];
int dp[MAXQ][MAXQ][MAXQ];

void init()
{
	forr(i, 0, GP + 1) forr(j, 0, GC + 1) forr(k, 0, GF + 1) dp[i][j][k] = -1;
	dp[0][0][0] = 1;
}

bool possible(int p, int c, int f)
{
	if (dp[p][c][f] == -1) {
		dp[p][c][f] = 0;
		forr(i, 0, N) {
			if (p - P[i] > -1 && c - C[i] > -1 && f - F[i] > -1
				&& possible(p - P[i], c - C[i], f - F[i])) {
				dp[p][c][f] = 1;
				break;
			}
		}
	}
	return dp[p][c][f] == 1;
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &T);
	forr(t, 1, T + 1) {
		scanf("%d %d %d\n", &GP, &GC, &GF);
		scanf("%d\n", &N);
		forr(i, 0, N) scanf("%d %d %d\n", &P[i], &C[i], &F[i]);
		init();
		if (possible(GP, GC, GF)) printf("Case #%d: yes\n", t);
		else printf("Case #%d: no\n", t);
	}
	return 0;
}