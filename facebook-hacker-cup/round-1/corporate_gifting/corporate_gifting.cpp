#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int lli;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

struct edge {int v, next;};

#define MAXN 200005

int T;
int N;
int gph_size;
int first[MAXN], last[MAXN];
edge gph[MAXN];
int remaining; bool done[MAXN];
bool vst[MAXN];
int fp[MAXN], fm[MAXN];

void init_gph()
{
    gph_size = 0;
    fill(first, first + N, -1);
    fill(last, last + N, -1);
}

void add_edge(int u, int v)
{
    int inx = gph_size; ++gph_size;
    gph[inx].v = v;
    gph[inx].next = -1;
    if (last[u] == -1) {
        first[u] = last[u] = inx;
    }
    else {
        gph[last[u]].next = inx;
        last[u] = inx;
    }
}

void calculate_fp_fm(int u)
{
    vst[u] = true;
    fp[u] = 1; fm[u] = 0;
    for(int inx = first[u]; inx != -1; inx = gph[inx].next) {
        int v = gph[inx].v;
        if (!done[v] && !vst[v]) {
            calculate_fp_fm(v);
            fp[u] += fm[v];
            fm[u] += max(fp[v], fm[v]);
        }
    }
}

void mark_done_nodes_maybe(int u);
void mark_done_nodes_no(int u);

void mark_done_nodes_maybe(int u)
{
    if (fp[u] > fm[u]) {
        --remaining; done[u] = true;
        for(int inx = first[u]; inx != -1; inx = gph[inx].next) {
            int v = gph[inx].v;
            if (!done[v]) {
                mark_done_nodes_no(v);
            }
        }
    }
    else {
        for(int inx = first[u]; inx != -1; inx = gph[inx].next) {
            int v = gph[inx].v;
            if (!done[v]) {
                mark_done_nodes_maybe(v);
            }
        }
    }
}

void mark_done_nodes_no(int u)
{
    for(int inx = first[u]; inx != -1; inx = gph[inx].next) {
        int v = gph[inx].v;
        if (!done[v]) {
            mark_done_nodes_maybe(v);
        }
    }
}

lli solve()
{
    lli ans = 0, it = 1;
    remaining = N; fill(done, done + N, false);
    while (remaining > 0) {
        fill(vst, vst + N, false);
        forr(i, 0, N) if (!done[i] && !vst[i]) {
            calculate_fp_fm(i);
            mark_done_nodes_maybe(i);
            ans += it * max(fp[i], fm[i]);
        }
        ++it;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int u;
    scanf("%d\n", &T);
    forr(t, 1, T + 1) {
        scanf("%d\n", &N);
        init_gph();
        scanf("%d ", &u); // 0
        forr(i, 1, N - 1) scanf("%d ", &u), --u, add_edge(u, i);
        scanf("%d\n", &u), --u, add_edge(u, N - 1);
        lli ans = solve();
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}