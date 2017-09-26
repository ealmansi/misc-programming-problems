// 20233056  2017-09-26 23:00:44 emilio  Range Minimum Query accepted edit    ideone it 0.10  16M CPP14
// http://www.spoj.com/problems/RMQSQ/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using vi = vector<int>;

#define rg(i, f, t) for (int i = f; i < t; ++i)

#define MAXN 100005

int N, Q;
vi arr(MAXN), rmq(4 * MAXN, numeric_limits<int>::max());

int left(int i) {
  return 2 * i + 1;
}

int right(int i) {
  return 2 * i + 2;
}

int mid(int l, int r) {
  return (l + r) / 2;
}

int _query(int i, int l, int r, int a, int b) {
  if (r <= l || b <= a) {
    return numeric_limits<int>::max();
  }
  if (l == a && r == b) { // match
    return rmq[i];
  }
  else { // range
    return min(
      _query(left(i), l, mid(l, r), a, min(mid(l, r), b)),
      _query(right(i), mid(l, r), r, max(mid(l, r), a), b));
  }
}

int query(int a, int b) {
  return _query(0, 0, N, a, b + 1);
}

void _init(int i, int l, int r) {
  if (r <= l) { // empty
    return;
  }
  if (l + 1 == r) { // singleton
    rmq[i] = arr[l];
  }
  else { // range
    _init(left(i), l, mid(l, r));
    _init(right(i), mid(l, r), r);
    rmq[i] = min(rmq[left(i)], rmq[right(i)]);
  }
}

void init() {
  _init(0, 0, N);
}

int main() {
  cin >> N;
  rg(i, 0, N) {
    cin >> arr[i];
  }
  init();
  cin >> Q;
  rg(i, 0, Q) {
    int a, b;
    cin >> a >> b;
    cout << query(a, b) << endl;
  }
  return 0;
}
