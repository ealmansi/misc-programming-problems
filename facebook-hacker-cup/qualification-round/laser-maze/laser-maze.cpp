#include <iostream>
#include <queue>
using namespace std;

#define mp make_pair
#define fst first
#define snd second

#define forr(i, d, h) for (int i = (d); i < (h); ++i)
#define rforr(i, d, h) for (int i = (d); i > (h); --i)

typedef enum {EMPTY_SPACE, WALL, LEFT_TURRET, UP_TURRET, RIGHT_TURRET, DOWN_TURRET, LASERED} status;
status turrets[4] = {LEFT_TURRET, UP_TURRET, RIGHT_TURRET, DOWN_TURRET};

#define MAXM 105
#define MAXN 105

int T;
int M, N;
int start_i, start_j, goal_i, goal_j;
status mz[MAXM][MAXN][4];
int dist[MAXM][MAXN][4];

int bfs()
{
	forr(i, 0, M) forr(j, 0, N) forr(k, 0, 4) dist[i][j][k] = -1;
	dist[start_i][start_j][0] = 0;
	queue<pair<pair<int, int>, int> > q;
	q.push(mp(mp(start_i, start_j), 0));
	int i, j, k, ii, jj, kk;
	while (!q.empty()) {
		pair<pair<int, int>, int> t = q.front(); q.pop();
		i = t.fst.fst, j = t.fst.snd, k = t.snd;
		if (i == goal_i && j == goal_j) return dist[i][j][k];
		kk = (k + 1) % 4;
		ii = i, jj = j - 1;
		if (jj >= 0 && dist[ii][jj][kk] == -1 && mz[ii][jj][kk] == EMPTY_SPACE) {
			dist[ii][jj][kk] = dist[i][j][k] + 1;
			q.push(mp(mp(ii, jj), kk));
		}
		ii = i - 1, jj = j;
		if (ii >= 0 && dist[ii][jj][kk] == -1 && mz[ii][jj][kk] == EMPTY_SPACE) {
			dist[ii][jj][kk] = dist[i][j][k] + 1;
			q.push(mp(mp(ii, jj), kk));
		}
		ii = i, jj = j + 1;
		if (jj <= N - 1 && dist[ii][jj][kk] == -1 && mz[ii][jj][kk] == EMPTY_SPACE) {
			dist[ii][jj][kk] = dist[i][j][k] + 1;
			q.push(mp(mp(ii, jj), kk));
		}
		ii = i + 1, jj = j;
		if (ii <= M - 1 && dist[ii][jj][kk] == -1 && mz[ii][jj][kk] == EMPTY_SPACE) {
			dist[ii][jj][kk] = dist[i][j][k] + 1;
			q.push(mp(mp(ii, jj), kk));
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	cin >> T;
	forr(t, 1, T + 1) {
		cin >> M >> N;
		forr(i, 0, M) forr(j, 0, N) {
			char c;
			cin >> c;
			switch(c) {
			case '.':
				forr(k, 0, 4) mz[i][j][k] = EMPTY_SPACE;
				break;
			case '#':
				forr(k, 0, 4) mz[i][j][k] = WALL;
				break;
			case 'S':
				start_i = i, start_j = j;
				forr(k, 0, 4) mz[i][j][k] = EMPTY_SPACE;
				break;
			case 'G':
				goal_i = i, goal_j = j;
				forr(k, 0, 4) mz[i][j][k] = EMPTY_SPACE;
				break;
			case '<':
				forr(k, 0, 4) mz[i][j][k] = turrets[(k + 0) % 4];
				break;
			case '^':
				forr(k, 0, 4) mz[i][j][k] = turrets[(k + 1) % 4];
				break;
			case '>':
				forr(k, 0, 4) mz[i][j][k] = turrets[(k + 2) % 4];
				break;
			case 'v':
				forr(k, 0, 4) mz[i][j][k] = turrets[(k + 3) % 4];
				break;
			default:
				break;
			}
		}
		forr(i, 0, M) forr(j, 0, N) forr(k, 0, 4) {
			switch(mz[i][j][k]) {
			case LEFT_TURRET:
				rforr(jj, j - 1, -1) {
					if (mz[i][jj][k] != EMPTY_SPACE && mz[i][jj][k] != LASERED) break;
					mz[i][jj][k] = LASERED;
				}
				break;
			case UP_TURRET:
				rforr(ii, i - 1, -1) {
					if (mz[ii][j][k] != EMPTY_SPACE && mz[ii][j][k] != LASERED) break;
					mz[ii][j][k] = LASERED;
				}
				break;
			case RIGHT_TURRET:
				forr(jj, j + 1, N) {
					if (mz[i][jj][k] != EMPTY_SPACE && mz[i][jj][k] != LASERED) break;
					mz[i][jj][k] = LASERED;
				}
				break;
			case DOWN_TURRET:
				forr(ii, i + 1, M) {
					if (mz[ii][j][k] != EMPTY_SPACE && mz[ii][j][k] != LASERED) break;
					mz[ii][j][k] = LASERED;
				}
				break;
			default:
				break;
			}
		}
		int ans = bfs();
		if (ans != -1) cout << "Case #" << t << ": " << ans << endl;
		else cout << "Case #" << t << ": impossible" << endl;
	}
	return 0;
}