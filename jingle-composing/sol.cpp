// Problem: Jingle Composing
// 1530716  4481  Jingle Composing  Accepted  C++ 0.098 2014-08-31 00:32:04
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2482

#include <iostream>
using namespace std;

string s;
int main(int argc, char const *argv[])
{
  cin >> s;
  while (s != "*")
  {
    int length, count = 0;
    for (int i = 1; i < s.size(); ++i)
    {
      length = 0;
      while (s[i] != '/')
      {
        switch (s[i])
        {
        case 'W': length += 64; break;
        case 'H': length += 32; break;
        case 'Q': length += 16; break;
        case 'E': length += 8; break;
        case 'S': length += 4; break;
        case 'T': length += 2; break;
        case 'X': length += 1; break;
        }
        ++i;
      }
      if (length == 64) ++count;
    }
    cout << count << endl;
    cin >> s;
  }
  return 0;
}