// 1530726  4476  Electric Bill Accepted  C++ 0.003 2014-08-31 01:37:58
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2477

#include <iostream>
using namespace std;

int A, B;

int price(int c)
{
  int p = 0;
  if (c > 1000000) p = p + 7 * (c - 1000000), c = 1000000;
  if (c > 10000) p = p + 5 * (c - 10000), c = 10000;
  if (c > 100) p = p + 3 * (c - 100), c = 100;
  p = p + 2 * c;
  return p;
}

int inv_price(int p)
{
  int c = 0;
  if (p > 2 * 100 + 3 * 9900 + 5 * 990000)
    c = (p - 2 * 100 - 3 * 9900 - 5 * 990000) / 7 + 100 + 9900 + 990000;
  else if (p > 2 * 100 + 3 * 9900)
    c = (p - 2 * 100 - 3 * 9900) / 5 + 100 + 9900;
  else if (p > 2 * 100)
    c = (p - 2 * 100) / 3 + 100;
  else
    c = (p) / 2;
  return c;
}

int main(int argc, char const *argv[])
{
  cin >> A >> B;
  while (A != 0)
  {
    int s = inv_price(A);
    int lo = (s + 1) / 2 - 1, mid, hi = s;
    bool done = false;
    while (!done)
    {
      mid = (lo + hi) / 2;
      int c = price(mid) - price(s - mid);
      if (c < B) lo = mid;
      else if (c == B) done = true;
      else hi = mid;
    }
    cout << price(s - mid) << endl;

    cin >> A >> B;
  }
  return 0;
}