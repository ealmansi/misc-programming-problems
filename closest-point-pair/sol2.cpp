// http://www.spoj.com/problems/CLOPPAIR/
// 13344806	2015-01-04 22:26:53	emilio	Closest Point Pair	accepted	 edit  run	0.55	3.3M	 C++ 4.9
#include <cstdio>
#include <cmath>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii,int> ppi;
typedef set<pair<pdd,int> > band;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)
#define mp make_pair
#define fst first
#define snd second

#define MAXN 50005
int N;
ppi P[MAXN];
band B;

long double sq(int x)
{
	return 1.0 * x * x;
}

long double dist(int i, int j)
{
	return sqrt(sq(P[i].fst.fst - P[j].fst.fst) + sq(P[i].fst.snd - P[j].fst.snd));
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &N);
	forr(i, 0, N) {
		scanf("%d %d\n", &P[i].fst.fst, &P[i].fst.snd);
		P[i].snd = i;
	}
	sort(P, P + N);
	int a, b;
	long double min_dist = 1e9;
	for (int i = 0, j = 0; i < N; ++i) {
		while(P[j].fst.fst <= P[i].fst.fst - min_dist) {
			B.erase(mp(mp(P[j].fst.snd, P[j].fst.fst), j));
			++j;
		}
		band::iterator it = B.lower_bound(mp(mp(P[i].fst.snd - min_dist, -1e9), -1));
		for (; it != B.end() && it->fst.fst < P[i].fst.snd + min_dist; ++it) {
			long double curr_dist = dist(it->snd, i);
			if (curr_dist < min_dist) {
				min_dist = curr_dist;
				a = it->snd;
				b = i;
			}
		}
		B.insert(mp(mp(P[i].fst.snd, P[i].fst.fst), i));
	}
	printf("%d %d %.6Lf\n", min(P[a].snd, P[b].snd), max(P[a].snd, P[b].snd), min_dist);
	return 0;
}