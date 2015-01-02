// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=658&page=show_problem&problem=4835
// 1625057	6823	Counting substhreengs	Accepted	C++	0.139	2015-01-02 04:48:30
#include <iostream>
using namespace std;
#define forr(i, d, h) for (int i = (d); i < (h); ++i)

int main(int argc, char const *argv[])
{
	string line;
	unsigned long long ans;
	int mod_sum;
	int seen[3];
	while(cin >> line) {
		ans = 0;
		mod_sum = 0;
		seen[0] = 1, seen[1] = 0, seen[2] = 0;
		forr(i, 0, line.size()) {
			if ('0' <= line[i] && line[i] <= '9') {
				mod_sum = (mod_sum + line[i] - '0') % 3;
				ans += seen[mod_sum];
				++seen[mod_sum];
			}
			else {
				mod_sum = 0;
				seen[0] = 1, seen[1] = 0, seen[2] = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}