// Problem: Helping Cupid
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=658&page=show_problem&problem=4840
// 1625129	6828	Help cupid	Accepted	C++	0.009	2015-01-02 18:20:49
#include <iostream>
#include <algorithm>
using namespace std;
#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 1005
int n;
int t[MAXN];

int diff(int i, int j)
{
	return min(abs(t[i] - t[j]), 24 - abs(t[i] - t[j]));
}

int main(int argc, char const *argv[])
{
	int sum, ans;
	while (cin >> n) {
		forr(i, 0, n) cin >> t[i];
		sort(t, t + n);
		sum = 0;
		forr(i, 0, n / 2) sum += diff(2 * i, 2 * i + 1);
		ans = sum;
		sum = diff(0, n - 1);
		forr(i, 0, n / 2 - 1) sum += diff(2 * i + 1, 2 * i + 2);
		ans = min(ans, sum);
		cout << ans << endl;
	}
	return 0;
}