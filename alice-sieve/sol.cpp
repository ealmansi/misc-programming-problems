// http://www.spoj.com/problems/ALICESIE/
// 13294044	2014-12-28 22:23:46	emilio	Alice Sieve	accepted	 edit  run	0.21	2.6M	 C++ 4.3.2

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << (n + 1) / 2 << endl;
	}
	return 0;
}