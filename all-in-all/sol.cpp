// Problem: All in All
// http://poj.org/problem?id=1936
// 13798884 ealmansi    1936    Accepted    400K    0MS C++ 527B    2015-01-21 06:17:03

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string s, t;
    while (cin >> s) {
        cin >> t;
        int i, j = 0;
        for (i = 0; i < s.size(); ++i) {
            while (j < t.size() && s[i] != t[j]) ++j;
            if (j == t.size()) break;
            ++j;
        }
        if (i == s.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}