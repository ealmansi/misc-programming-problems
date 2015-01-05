// Problem: Galaxy Collision
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=9
// 1625567	6827	Galaxy collision	Accepted	C++11	3.172	2015-01-05 04:44:44
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

#define fst first
#define snd second
#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 50005
int N;
pii ps[MAXN];
vi g[MAXN];
unordered_map<long long int, int> galaxy;
int color[MAXN];
int color_count[2];

long long int hsh(int x, int y)
{
	return 4294967296ll * x + y;
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
		galaxy.clear();
		forr(i, 0, N) galaxy[hsh(ps[i].fst, ps[i].snd)] = i;
		// build graph
		forr(i, 0, N) g[i].clear();
		forr(i, 0, N) {
			forr(dx, -5, 6) forr(dy, -5, 6) if (dx | dy && dx * dx + dy * dy <= 25) {
				auto it = galaxy.find(hsh(ps[i].fst + dx, ps[i].snd + dy));
				if (it != galaxy.end()) {
					g[i].push_back(it->snd);
				}
			}
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