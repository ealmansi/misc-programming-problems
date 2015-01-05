// Problem: Galaxy Collision
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=9
// 1625558	6827	Galaxy collision	Accepted	C++	0.462	2015-01-05 01:32:13
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<pii, int> tiii;

#define mp(a, b) make_pair((a), (b))
#define fst first
#define snd second
#define mt(a, b, c) mp(mp((a), (b)), (c))
#define tfst fst.fst
#define tsnd fst.snd
#define ttrd snd
#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 50005
int N;
pii ps[MAXN];
vi g[MAXN];
set<tiii> band;
int color[MAXN];
int color_count[2];

bool points_are_close(int i, int j)
{
	return (1.0 * (ps[i].fst - ps[j].fst) * (ps[i].fst - ps[j].fst) +
			1.0 * (ps[i].snd - ps[j].snd) * (ps[i].snd - ps[j].snd)) <= 25.0;
}

void visit(int i, int c)
{
	color[i] = c; ++color_count[c];
	forr(j, 0, g[i].size()) if (color[g[i][j]] == -1) visit(g[i][j], 1 - c);
}

int main(int argc, char const *argv[])
{
	while (scanf("%d\n", &N) != EOF) {
		forr(i, 0, N) scanf("%d %d\n", &ps[i].fst, &ps[i].snd);
		sort(ps, ps + N);
		forr(i, 0, N) g[i].clear();
		band.clear();
		// sweep line
		int j = 0;
		forr(i, 0, N) {
			while (ps[j].fst < ps[i].fst - 5) {
				band.erase(mt(ps[j].snd, ps[j].fst, j));
				++j;
			}
			set<tiii>::iterator it = band.lower_bound(mt(ps[i].snd - 5, ps[i].fst - 5, j));
			for (; it != band.end() && it->tfst <= ps[i].snd + 5; ++it) {
				if (points_are_close(it->ttrd, i)) {
					g[i].push_back(it->ttrd);
					g[it->ttrd].push_back(i);
				}
			}
			band.insert(mt(ps[i].snd, ps[i].fst, i));
		}
		// graph coloring
		int ans = 0;
		fill(color, color + N, -1);
		forr(i, 0, N) if (color[i] == -1) {
			forr(j, 0, 2) color_count[j] = 0;
			visit(i, 0);
			ans += *min_element(color_count, color_count + 2);
		}
		cout << ans << endl;
	}
	return 0;
}