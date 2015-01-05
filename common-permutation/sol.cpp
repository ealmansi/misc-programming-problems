// Problem: Common Permutation
//  http://www.spoj.com/problems/CPRMT/
// 13276409	2014-12-27 00:56:34	emilio	Common Permutation	accepted	 edit  run	0.00	2.8M	 C++

#include <iostream>
#include <algorithm>
using namespace std;

#define ALPH_LEN ('z' - 'a' + 1)
int a_hist[ALPH_LEN], b_hist[ALPH_LEN];

int main(int argc, char const *argv[]) {

	string a, b;
	while(cin >> a) {
		cin >> b;
		fill(a_hist, a_hist + ALPH_LEN, 0);
		fill(b_hist, b_hist + ALPH_LEN, 0);
		for (int i = 0; i < a.size(); ++i) {
			++a_hist[a[i] - 'a'];
		}
		for (int i = 0; i < b.size(); ++i) {
			++b_hist[b[i] - 'a'];
		}
		for (int i = 0; i < ALPH_LEN; ++i) {
				for (int j = 0; j < min(a_hist[i], b_hist[i]); ++j) {
					cout << (char) (i + 'a');
				}
		}
		cout << endl;
	}

	return 0;
}