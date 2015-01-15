// Problem: Easy Dijkstra Problem
// http://www.spoj.com/problems/EZDIJKST/
// 13430003 2015-01-15 05:20:13 emilio  Easy Dijkstra Problem   accepted     edit  run   0.00    3.4M     C++ 4.9

#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef priority_queue<pii,vector<pii>,greater<pii> > min_heap;

#define mp make_pair
#define fst first
#define snd second

#define INF ((int)2e9)
#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 10005
#define MAXM 10005

struct node {int v, w, next;};

int T;
int N, M;
int a, b, c;
int A, B;
int gph_size, first[MAXN], last[MAXN];
node gph[MAXM];
bool visited[MAXN];
int dist[MAXN];

void init_graph()
{
    gph_size = 0;
    forr(i, 0, N) first[i] = last[i] = -1;
}

void addEdge(int u, int v, int w)
{
    int idx = gph_size; ++gph_size;
    gph[idx].v = v;
    gph[idx].w = w;
    gph[idx].next = -1;
    if (first[u] == -1) {
        first[u] = last[u] = idx;
    }
    else {
        gph[last[u]].next = idx;
        last[u] = idx;
    }
}

int dijkstra()
{
    forr(i, 0, N) visited[i] = false;
    forr(i, 0, N) dist[i] = INF;
    min_heap q;
    q.push(mp(0, A)); dist[A] = 0;
    while(!q.empty()) {
        int u = q.top().snd; q.pop();
        if(!visited[u]) {
            visited[u] = true;
            for(int idx = first[u]; idx != -1; idx = gph[idx].next) {
                int v = gph[idx].v, w = gph[idx].w;
                if (!visited[v] && dist[u] + w < dist[v]) {
                    q.push(mp(dist[u] + w, v)); dist[v] = dist[u] + w;
                }
            }
        }
    }
    return dist[B];
}

int main(int argc, char const *argv[])
{
    scanf("%d\n", &T);
    forr(t, 1, T + 1) {
        scanf("%d %d\n", &N, &M);
        init_graph();
        forr(i, 0, M) {
            scanf("%d %d %d\n", &a, &b, &c); --a, --b;
            addEdge(a, b, c);
        }
        scanf("%d %d\n", &A, &B); --A, --B;
        int dist = dijkstra();
        if (dist != INF) printf("%d\n", dist);
        else printf("NO\n");
    }
    return 0;
}