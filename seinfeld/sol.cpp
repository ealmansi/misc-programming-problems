// https://www.spoj.com/problems/ANARC09A/
// 22840639 	2018-12-07 21:14:01 	emilio	Seinfeld	accepted edit    ideone it 	0.00 	15M 	CPP14
#include <iostream>
using namespace std;

#define MAX_N 2005

int solve (const string& line);

int main ()
{
  string line;
  for (int i = 0; ;++i) {
    cin >> line;
    if (line[0] == '-') {
      break;
    }
    cout << (i + 1) << ". " << solve(line) << endl;
  }
  return 0;
}

int solve (const string& line) {
  int c = 0, a = 0;
  for (int i = 0; i < line.size(); ++i) {
    if (c == 0) {
      if (line[i] == '{') {
        ++c;
      } else {
        ++a;
        ++c;
      }
    } else {
      if (line[i] == '{') {
        ++c;
      } else {
        --c;
      }
    }
  }
  a = a + c / 2;
  return a;
}
