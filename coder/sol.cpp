// 7279859  Practice: apaapa  384A - 11   GNU C++   Accepted  78 ms   4 KB  2014-07-28 21:41:58   2014-07-28 21:41:58
// http://codeforces.com/problemset/problem/384/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    #ifdef APAAPA
        freopen("test.in", "r", stdin);
    #endif
    
    int N;
    cin >> N;
    cout << (N * N + 1) / 2 << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if( (i + j) % 2 == 0 )
                cout << "C";
            else
                cout << ".";
        }
        cout << endl;
    }
    
    
    return 0;
}