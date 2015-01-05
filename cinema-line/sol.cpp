// Problem: Cinema Line
// 7286850  Practice: apaapa  349A - 43   GNU C++   Accepted  92 ms   4 KB  2014-07-29 21:22:20   2014-07-29 21:22:20
// http://codeforces.com/contest/349/problem/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    int n, b;
    int cant_25 = 0, cant_50 = 0, cant_100 = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        switch (b)
        {
            case 25:
            {
                ++cant_25;
                break;
            }
            case 50:
            {
                if (cant_25 > 0)
                {
                    --cant_25;
                    ++cant_50;
                }
                else
                {
                    cout << "NO" << endl;return 0;
                }
                break;
            }
            case 100:
            {
                if (cant_50 > 0 and cant_25 > 0)
                {
                    --cant_50; --cant_25; ++cant_100;
                }
                else if (cant_25 >= 3)
                {
                    cant_25 -= 3;++cant_100;
                }
                else
                {
                    cout << "NO" << endl;return 0;
                }
                break;
            }
            default:
                {cout << "NO" << endl;return 0;}
        }
    }
    {cout << "YES" << endl;return 0;}
}