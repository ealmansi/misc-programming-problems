// 12320399 2014-09-07 05:44:11 emilio  Round-Robin Scheduling  accepted   edit  run 4.98  4.2M   C++ 4.3.2
// http://www.spoj.com/problems/RRSCHED/

#include <iostream>

#include <utility>
#include <algorithm>
using namespace std;

#define mp make_pair

typedef long long int lli;

#define MAX_N 50005
lli N;
pair<lli,lli> tareas[MAX_N];
lli res[MAX_N];
lli tree[MAX_N];

void update(lli ind, lli val)
{
  while (ind <= N)
  {
    tree[ind] += val;
    ind += (ind & -ind);
  }
}

lli query(lli ind)
{
  lli res = 0;
  while (ind > 0)
  {
    res += tree[ind];
    ind -= (ind & -ind);
  }
  return res;
}

bool comp(const pair<lli,lli>& a, const pair<lli,lli>& b)
{
  return (a.second < b.second) or (a.second == b.second and a.first < b.first);
}

int main(int argc, char const *argv[])
{
  cin >> N;
  for (lli i = 1; i <= N; ++i)
  {
    lli t;
    cin >> t;
    tareas[i] = mp(i, t);
  }
  sort(tareas + 1, tareas + N + 1, comp);

  fill(tree + 1, tree + N + 1, 0);
  for (int i = 1; i <= N; ++i)
    update(i, 1);
  
  lli acum = 0, delta_t;
  for (int i = 1; i <= N; ++i)
  {
    delta_t = tareas[i].second - ((i > 1) ? tareas[i - 1].second : 0);
    acum += (N - (i - 1)) * delta_t;
    res[tareas[i].first] = acum - ((N - (i - 1)) - query(tareas[i].first));
    update(tareas[i].first, -1);
  }

  for (int i = 1; i <= N; ++i)
    cout << res[i] << endl;
  return 0;
}