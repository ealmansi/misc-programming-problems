// Problem: 4 Values Whose Sum Is 0
// http://www.spoj.com/problems/SUMFOUR/
// 13292632	2014-12-28 18:49:06	emilio	4 values whose sum is 0	accepted	 edit  run	1.95	2.8M	 C++ 4.3.2

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<int> vi;

#define MAXN 4005

int main(int argc, char const *argv[]) {
	
	int n;
	scanf("%d\n", &n);
	vi a(n), b(n), c(n), d(n);
	vi ab(n * n), cd(n * n);
	vi ab_count(n * n, 0), cd_count(n * n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d %d\n", &a[i], &b[i], &c[i], &d[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ab[i * n + j] = a[i] + b[j];
			cd[i * n + j] = c[i] + d[j];
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end(), greater<int>());
	for (int i = 0, j; i < n * n; i += ab_count[i]) {
		for (j = i + 1; j < n * n && ab[i] == ab[j]; ++j);
		ab_count[i] = j - i;
	}
	for (int i = 0, j; i < n * n; i += cd_count[i]) {
		for (j = i + 1; j < n * n && cd[i] == cd[j]; ++j);
		cd_count[i] = j - i;
	}
	int i = 0, j = 0, ans = 0, sum;
	while (i < n * n && j < n * n) {
		sum = ab[i] + cd[j];
		if (sum > 0) j += cd_count[j];
		else if (sum < 0) i += ab_count[i];
		else {
			ans += ab_count[i] * cd_count[j];
			i += ab_count[i];
			j += cd_count[j];
		}
	}
	cout << ans << endl;
	return 0;
}