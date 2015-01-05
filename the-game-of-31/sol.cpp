// Problem: The Game Of 31
/*
12320316  2014-09-07 05:18:29 emilio  The game of 31  accepted   edit  run 0.00  2.8M   C++ 4.3.2
// http://www.spoj.com/problems/GAME31/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cstdlib>

using namespace std;

int mem[5][5][5][5][5][5];

bool f(int c1, int c2, int c3, int c4, int c5, int c6)
{
  if (mem[c1][c2][c3][c4][c5][c6] != -1)
    return mem[c1][c2][c3][c4][c5][c6];
  
  int sum = 1 * c1 + 2 * c2 + 3 * c3 + 4 * c4 + 5 * c5 + 6 * c6;

  if(c1 < 4 && sum + 1 <= 31 && not f(c1 + 1, c2, c3, c4, c5, c6)) goto win;
  if(c2 < 4 && sum + 2 <= 31 && not f(c1, c2 + 1, c3, c4, c5, c6)) goto win;
  if(c3 < 4 && sum + 3 <= 31 && not f(c1, c2, c3 + 1, c4, c5, c6)) goto win;
  if(c4 < 4 && sum + 4 <= 31 && not f(c1, c2, c3, c4 + 1, c5, c6)) goto win;
  if(c5 < 4 && sum + 5 <= 31 && not f(c1, c2, c3, c4, c5 + 1, c6)) goto win;
  if(c6 < 4 && sum + 6 <= 31 && not f(c1, c2, c3, c4, c5, c6 + 1)) goto win;
  goto lose;

lose:
  mem[c1][c2][c3][c4][c5][c6] = 0;
  return mem[c1][c2][c3][c4][c5][c6];
win:
  mem[c1][c2][c3][c4][c5][c6] = 1;
  return mem[c1][c2][c3][c4][c5][c6];
}

int main(){

  for (int i1 = 0; i1 < 5; i1++)
  for (int i2 = 0; i2 < 5; i2++)
  for (int i3 = 0; i3 < 5; i3++)
  for (int i4 = 0; i4 < 5; i4++)
  for (int i5 = 0; i5 < 5; i5++)
  for (int i6 = 0; i6 < 5; i6++)
    mem[i1][i2][i3][i4][i5][i6] = -1;
  
  string line;
  while(getline(cin, line))
  {
    int c[7] = {-1, 0, 0, 0, 0, 0, 0};
    for (unsigned int i = 0; i < line.size(); i++)
      ++c[line[i] - '0'];

    if (f(c[1], c[2], c[3], c[4], c[5], c[6]))
      cout << line << " " << ((line.size() % 2 == 0) ? "A" : "B") << endl;
    else
      cout << line << " " << ((line.size() % 2 == 0) ? "B" : "A") << endl;
  }
  
  return 0;
}

