// Problem: Expanding Rods
// http://poj.org/problem?id=1905
// 13766125	ealmansi	1905	Accepted	164K	0MS	C++	596B	2015-01-07 07:37:23
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int L, n; double C;
	while (scanf("%d %d %lf", &L, &n, &C), L >= 0) {
		double ratio, Lp;
		ratio = 1.0 + n * C, Lp = ratio * L;
		if (ratio < 1.00001) {
			printf("0.000\n");
			continue;
		}
		double low = 0, mid = -1, high = 3.14159265358979323846 / 2.0;
		while (high - low > 1e-12) {
			mid = (high + low) / 2.0;
			if (mid > ratio * sin(mid)) high = mid;
			else low = mid;
		}
		double ans = Lp / 2.0 / mid * (1 - cos(mid));
		printf("%.3lf\n", ans);
	}
	return 0;
}