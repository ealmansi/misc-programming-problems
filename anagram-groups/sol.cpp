// Problem: Anagram Groups
// http://poj.org/problem?id=2408
// 13802077 ealmansi    2408    Accepted    3364K   204MS   C++ 1266B   2015-01-22 05:43:30
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef map<string, vs> msvs;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

bool groups_compare(const vs& a, const vs& b)
{
    return a.size() > b.size() ||
            (a.size() == b.size() && a[0] < b[0]);
}

int main(int argc, char const *argv[])
{
    string word, word_st;
    msvs m_groups;
    while (cin >> word) {
        word_st = word;
        sort(word_st.begin(), word_st.end());
        m_groups[word_st].push_back(word);
    }
    vvs groups;
    for (msvs::iterator it = m_groups.begin(); it != m_groups.end(); ++it) {
        groups.push_back(it->second);
    }
    forr (i, 0, groups.size()) {
        sort(groups[i].begin(), groups[i].end());
    }
    sort(groups.begin(), groups.end(), groups_compare);
    forr (i, 0, min((int)groups.size(), 5)) {
        cout << "Group of size " << groups[i].size() << ": ";
        forr (j, 0, groups[i].size()) if (j == 0 || groups[i][j - 1] != groups[i][j]) {
            cout << groups[i][j] << " ";
        }
        cout << "." << endl;
    }
    return 0;
}