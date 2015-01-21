#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

int T;
long long int N, M;

int main(int argc, char const *argv[])
{
	scanf("%d\n", &T);
	forr(t, 0, T) {
		scanf("%lld\n", &N);
		vi ds;
		M = N; while(M > 0) { ds.push_back(M % 10); M /= 10; }
		reverse(ds.begin(), ds.end());
		long long int min_val = N, max_val = N;
		forr(i, 0, ds.size()) forr(j, i + 1, ds.size()) {
			if (i > 0 || ds[j] != 0) {
				swap(ds[i], ds[j]);
				M = 0; forr(k, 0, ds.size()) M = 10 * M + ds[k];
				min_val = min(M, min_val);
				max_val = max(M, max_val);
				swap(ds[i], ds[j]);
			}
		}
		printf("Case #%d: %lld %lld\n", t + 1, min_val, max_val);
	}
	return 0;
}