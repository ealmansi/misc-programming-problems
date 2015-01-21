#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define forr(i, d, h) for (int i = (d); i < (h); ++i)

#define nil ((trie_node*) 0)

struct trie_node {
    trie_node() {fill(next, next + 'z' - 'a' + 1, nil);}
    trie_node* next['z' - 'a' + 1];
};

int T;
int N;
trie_node* root;

int add_word(const string& w)
{
    trie_node* nd = root;
    int count = -1;
    forr(i, 0, w.size()) {
        if (nd->next[w[i] - 'a'] == nil) {
            nd->next[w[i] - 'a'] = new trie_node();
            if (count == -1) {
                count = i + 1;
            }
        }
        nd = nd->next[w[i] - 'a'];
    }
    if (count == -1) {
        count = w.size();
    }
    return count;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    forr(t, 1, T + 1) {
        cin >> N;
        root = new trie_node();
        int ans = 0;
        forr(n, 0, N) {
            string w;
            cin >> w;
            ans += add_word(w);
        }
        queue<trie_node*> q;
        q.push(root);
        while(!q.empty()) {
            trie_node* n = q.front(); q.pop();
            forr(i, 0, 'z' - 'a' + 1) {
                if (n->next[i] != nil) q.push(n->next[i]);
            }
            delete n;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}