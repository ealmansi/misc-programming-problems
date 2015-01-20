// Problem: A Needle in the Haystack
// http://www.spoj.com/problems/NHAY/
// 13479780 2015-01-20 22:36:08 emilio  A Needle in the Haystack    accepted     edit  run   0.16    3.2M     C++ 4.9
#include <cstdio>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

int m;
char *P;
int *I;
bool no_matches;
char c;
int inx_t, inx_p;

void kmp_preprocess()
{
    forr (i, 0, m) {
        int j = i - 1;
        while (j > -1 && P[I[j] + 1] != P[i]) {
            j = I[j];
        }
        I[i] = j > -1 ? I[j] + 1 : -1;
    }
    inx_p = 0;
}

bool kmp_match(char c)
{
    bool match = false;
    while (inx_p > -1 && c != P[inx_p]) {
        inx_p = inx_p > 0 ? I[inx_p - 1] + 1 : -1;
    }
    ++inx_p;
    if (inx_p == m) {
        match = true;
        inx_p = I[inx_p - 1] + 1;
    }
    return match;
}

int main(int argc, char const *argv[])
{
    while (scanf("%d\n", &m) != EOF) {
        P = new char[m + 1]; I = new int[m];
        scanf("%s\n", P); kmp_preprocess();
        no_matches = true;
        inx_t = 0;
        while (c = getchar(), c != EOF && c != '\n') {
            if (kmp_match(c)) {
                printf("%d\n", inx_t - m + 1);
                no_matches = false;
            }
            ++inx_t;
        }
        if (no_matches) printf("\n");
        delete[] P; delete[] I;
    }
    return 0;
}