// Problem: Philosophers Stone
// http://www.spoj.com/problems/BYTESM2/
// 13276519	2014-12-27 01:45:33	emilio	Philosophers Stone	accepted	 edit  run	0.98	2.6M	 C++ 4.0.0-8

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_H 105
#define MAX_W 105

int T, h, w;
int mat[MAX_H][MAX_W], dp[MAX_H][MAX_W];

int main(int argc, char const *argv[]) {
	
	cin >> T;
	for (int k = 0; k < T; ++k) {
		cin >> h >> w;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> mat[i][j];
			}
		}
		for (int j = 0; j < w; ++j) {
			dp[0][j] = mat[0][j];
		}
		for (int i = 1; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				int max_r = -1;
				if (j > 0) {
					max_r = max(max_r, dp[i - 1][j - 1]);
				}
				max_r = max(max_r, dp[i - 1][j]);
				if (j + 1 < w) {
					max_r = max(max_r, dp[i - 1][j + 1]);
				}
				dp[i][j] = mat[i][j] + max_r;
			}
		}
		int ans = *max_element(dp[h - 1], dp[h - 1] + w);
		cout << ans << endl;
	}

	return 0;
}