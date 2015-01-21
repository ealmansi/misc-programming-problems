#include <cstdio>
#include <algorithm>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXN 10000005

int T;
int A, B, K;
int is_prime[MAXN], primacity[MAXN];

void init()
{
    fill(is_prime, is_prime + MAXN, 1);
    fill(primacity, primacity + MAXN, 0);
    forr(i, 2, MAXN) if (is_prime[i]) {
        primacity[i] = 1;
        int j = 2 * i;
        while (j < MAXN) {
            is_prime[j] = 0;
            ++primacity[j];
            j += i;
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    scanf("%d\n", &T);
    forr(t, 1, T + 1) {
        scanf("%d %d %d\n", &A, &B, &K);
        int ans = 0;
        forr(i, A, B + 1) {
            if (primacity[i] == K) ++ans;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}