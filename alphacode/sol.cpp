// Problem: Alphacode
// http://www.spoj.com/problems/ACODE/
// 13667682 2015-02-15 04:04:18 emilio  Alphacode accepted   edit  run 0.00  3.3M   C++ 4.9
#include <string>
#include <iostream>
using namespace std;

#define MAXL 5005

int mem[MAXL + 1];

bool between(int a, int b, int c)
{
  return a <= b && b <= c;
}

int f(string& line, int i)
{
  if (mem[i] == -1) {
    if (i == line.size()) {
      mem[i] = 1;
    }
    else {
      int ans = 0;
      if (line[i] - '0' > 0) {
        ans += f(line, i + 1);
        if (i < line.size() - 1
          && between(0, (line[i] - '0') * 10 + (line[i + 1] - '0'), 26)) {
          ans += f(line, i + 2);
        }
      }
      mem[i] = ans;
    }
  }
  return mem[i];
}

int main(int argc, char const *argv[])
{
  string line;
  while (cin >> line, line != "0") {
    for (int i = 0; i < line.size() + 1; ++i) mem[i] = -1;
    cout << f(line, 0) << endl;
  }
  return 0;
}