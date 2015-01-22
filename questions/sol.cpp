// Problem: Questions
// http://poj.org/problem?id=2359
// 13802184 ealmansi    2359    Accepted    392K    375MS   C++ 937B    2015-01-22 08:52:21
#include <cstdio>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define MAXL 30005

char q[MAXL];
int left[MAXL], right[MAXL];

int main(int argc, char const *argv[])
{
    int len = 0; char c;
    while (c = getchar(), c != EOF) if (c != '\n') {
        q[len] = c;
        left[len] = len - 1; right[len] = len + 1;
        ++len;
    }
    q[len] = '\0';
    left[0] = len - 1; right[len - 1] = 0;
    int pos = 0, prev, remaining = len;
    while (remaining > 1) {
        forr (_, 0, 1998 % remaining) pos = right[pos];
        right[left[pos]] = right[pos];
        left[right[pos]] = left[pos];
        pos = right[pos];
        --remaining;
    }
    switch (q[pos]) {
    case '?':
        printf("Yes\n");
        break;
    case ' ':
        printf("No\n");
        break;
    default:
        printf("No comments\n");
        break;
    }
    return 0;
}