// Problem: Mars Map
// http://www.spoj.com/problems/NKMARS/
//13345221		2015-01-05 00:08:31	Mars Map	100	 edit  run	1.12	3.4M	 C++ 4.9
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)
#define mp make_pair
#define fst first
#define snd second

#define MAXN 10005
int N;
int x1, y1, x2, y2;
pii xs[2 * MAXN], ys[2 * MAXN];
bool active_h[MAXN], active_v[MAXN];
int active_v_count;
int delta_y, active_hgt;
int ans;

int main(int argc, char const *argv[])
{
	cin >> N;
	forr(i, 0, N) {
		cin >> x1 >> y1 >> x2 >> y2;
		xs[2 * i] = mp(x1, i); xs[2 * i + 1] = mp(x2, i);
		ys[2 * i] = mp(y1, i); ys[2 * i + 1] = mp(y2, i);
	}
	sort(xs, xs + 2 * N);
	sort(ys, ys + 2 * N);
	ans = 0;
	fill(active_h, active_h + N, false);
	forr(i, 0, 2 * N) {
		active_h[xs[i].snd] = !active_h[xs[i].snd];
		if (i > 0) ans += (xs[i].fst - xs[i - 1].fst) * active_hgt;
		active_hgt = 0;
		fill(active_v, active_v + N, false); active_v_count = 0;
		forr(j, 0, 2 * N) if (active_h[ys[j].snd]) {
			active_v[ys[j].snd] = !active_v[ys[j].snd];
			if (active_v[ys[j].snd]) ++active_v_count; else --active_v_count;
			if (active_v[ys[j].snd] && active_v_count == 1) delta_y = ys[j].fst;
			else if (!active_v[ys[j].snd] && active_v_count == 0) active_hgt += ys[j].fst - delta_y;
		}
	}
	cout << ans << endl;
	return 0;
}