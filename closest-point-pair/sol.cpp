// Problem: Closest Point Pair
// http://www.spoj.com/problems/CLOPPAIR/
// 13344825	2015-01-04 22:31:18	emilio	Closest Point Pair	accepted	 edit  run	0.45	3.5M	 C++ 4.9
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)
#define mp make_pair
#define fst first
#define snd second

#define MAXN 50005
int N;
ppi _P[MAXN];
pii P[MAXN];
int a, b;
double dist, min_dist;

double compute_dist(int i, int j)
{
	return sqrt(1.0 * (P[i].fst - P[j].fst) * (P[i].fst - P[j].fst) +
			1.0 * (P[i].snd - P[j].snd) * (P[i].snd - P[j].snd));
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &N);
	forr(i, 0, N) {
		scanf("%d %d\n", &_P[i].fst.fst, &_P[i].fst.snd);
		_P[i].snd = i;
	}
	sort(_P, _P + N);
	forr(i, 0, N) P[i] = _P[i].fst;
	min_dist = 1e10;
	forr(i, 0, N) forr(j, i + 1, N) {
		if (P[i].fst + min_dist < P[j].fst) break;
		dist = compute_dist(i, j);
		if (dist < min_dist) {
			min_dist = dist;
			a = i;
			b = j;
		}
	}
	printf("%d %d %.6f\n", min(_P[a].snd, _P[b].snd), max(_P[a].snd, _P[b].snd), min_dist);
	return 0;
}