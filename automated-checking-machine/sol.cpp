// Problem: Automated Checking Machine
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=658&page=show_problem&problem=4833
// 1624830	6821	Automated Checking Machine	Accepted	C++11	0.003	2014-12-31 17:50:46
#include <iostream>
using namespace std;
#define forr(i, d, h) for (int i = (d); i < (h); ++i)

int x[5], y[5];

int main(int argc, char const *argv[])
{
	bool compatible;
	while (cin >> x[0]) {
		forr(i, 1, 5) cin >> x[i];
		forr(i, 0, 5) cin >> y[i];
		compatible = true;
		forr(i, 0, 5) if (x[i] + y[i] != 1) {
			compatible = false;
			break;
		}
		if (compatible) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	return 0;
}