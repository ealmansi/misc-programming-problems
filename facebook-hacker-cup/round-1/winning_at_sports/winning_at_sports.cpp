#include <cstdio>
#include <algorithm>
using namespace std;

#define MOD 1000000007

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXS 2005

int T;
int A, B;
int stressfree_mem[MAXS][MAXS];
int stressful_mem[MAXS][MAXS];

int stressfree(int a, int b)
{
    if (stressfree_mem[a][b] == -1) {
        int ans;
        if (a == A and b == B) {
            ans = 1;
        }
        else {
            ans = 0;
            if (a < A) ans = (ans + stressfree(a + 1, b)) % MOD;
            if (b < B and b + 1 < a) ans = (ans + stressfree(a, b + 1)) % MOD;
        }
        stressfree_mem[a][b] = ans;
    }
    return stressfree_mem[a][b];
}

int stressful(int a, int b)
{
    if (stressful_mem[a][b] == -1) {
        int ans;
        if (a == A and b == B) {
            ans = 1;
        }
        else {
            ans = 0;
            if (a < A and (a + 1 <= b or b == B)) ans = (ans + stressful(a + 1, b)) % MOD;
            if (b < B) ans = (ans + stressful(a, b + 1)) % MOD;
        }
        stressful_mem[a][b] = ans;
    }
    return stressful_mem[a][b];
}

int main(int argc, char const *argv[])
{
    scanf("%d\n", &T);
    forr(t, 1, T + 1) {
        scanf("%d-%d\n", &A, &B);
        forr(i, 0, A + 1) forr(j, 0, B + 1) stressfree_mem[i][j] = stressful_mem[i][j] = -1;
        printf("Case #%d: %d %d\n", t, stressfree(0, 0), stressful(0, 0));
    }
    return 0;
}