// http://www.spoj.com/problems/MAXLN/
// 13293431		2014-12-28 20:42:43	THE MAX LINES	accepted	 edit  run	0.02	2.6M	 C++ 4.3.2

#include <iostream>
using namespace std;

int T;
unsigned long long int r;

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> r;
		cout << "Case " << (i + 1) << ": " << (4 * r * r) << ".25" << endl;
	}
	return 0;
}