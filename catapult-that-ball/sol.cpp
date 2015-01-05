// Problem: Catapult That Ball
// 12427289 2014-09-22 04:15:47 emilio  Catapult that ball  accepted   edit  run 1.29  7.1M   C++ 4.3.2
// http://www.spoj.com/problems/THRBL/cstart=10

#include <iostream>
using namespace std;

/*  */

#define RMQ_n 16
#define RMQ_N (1<<RMQ_n)
#define RMQ_IDENTITY (-1)
int rmq_f(int a, int b) { return max(a,b); }
int rmq_t[RMQ_N][RMQ_n + 1], rmq_a[RMQ_N];

void rmq_init() {
  for (int x = 0; x < RMQ_N; x++)
    rmq_t[x][0] = rmq_a[x];
  for (int y = 1; y <= RMQ_n; y++)
    for (int x = 0; x < RMQ_N; x+=(1<<y))
      rmq_t[x][y] = rmq_f(rmq_t[x][y-1], rmq_t[x+(1<<(y-1))][y-1]);
}

void rmq_set(int x, int v) {
  rmq_t[x][0] = rmq_a[x] = v;
  for (int y = 1; y <= RMQ_n; y++) {
    int xx = x-(x&((1<<y)-1));
    rmq_t[xx][y] = rmq_f(rmq_t[xx][y-1], rmq_t[xx+(1<<(y-1))][y-1]);
  }
}

int rmq_get(int i, int j) {
  int res = RMQ_IDENTITY, h = 0; j++;
  while (i+(1<<h) <= j) {
    while ((i&((1<<(h+1))-1)) == 0 && i+(1<<(h+1)) <= j) h++;
    res = rmq_f(res, rmq_t[i][h]);
    i += (1<<h);
  }
  while (i < j) {
    while (i+(1<<h) > j) h--;
    res = rmq_f(res, rmq_t[i][h]);
    i += (1<<h);
  }
  return res;
}

/*  */

int N, M;

int main(int argc, char const *argv[])
{
  int H, A, B, ans = 0;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> H, rmq_a[i] = H;
  }
  rmq_init();
  for (int i = 0; i < M; ++i) {
    cin >> A >> B;
    --A, --B;
    if (A <= B) {
      if (rmq_get(A, B - 1) <= rmq_a[A])
        ++ans;
    }
    else {
      if (rmq_get(B + 1, A) <= rmq_a[A])
        ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}