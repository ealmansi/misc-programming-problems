// Problem: Drop The Triples
// 1548217  3930  Drop the Triples  Accepted  C++ 1.389 2014-09-20 03:54:36
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=294&problem=1931

#include <iostream>
using namespace std;

#define CARDS 13

int N;
int p1[CARDS], p2[CARDS];
int mem[1594323];

int encode(int p[CARDS]) {
  int code = 0;
  for (int i = 0; i < CARDS; ++i) {
    code = code * 3 + p[i];
  }
  return code;
}

int max_common(int p[CARDS]) {
  int code = encode(p);
  if (mem[code] == 0) {
    int max_count = 0;
    for (int i = 0; i < CARDS; ++i) if (p[i] > 0) {
      --p[i];
      for (int j = i; j < CARDS; ++j) if (p[j] > 0) {
        --p[j];
        for (int k = j; k < CARDS; ++k) if (p[k] > 0) {
          --p[k];
          if ((k + 1) < (i + 1) + (j + 1)) {
            max_count = max(max_count, 1 + max_common(p));
          }
          ++p[k];
        }
        ++p[j];
      }
      ++p[i];
    }
    mem[code] = max_count + 1;
  }
  return mem[code] - 1;
}

int main(int argc, char const *argv[]) {

  int c, p1_perfect, p1_common, p2_perfect, p2_common;

  cin >> N;
  while (N != 0) {

    p1_perfect = p1_common = p2_perfect = p2_common = 0;
    for (int i = 0; i < CARDS; ++i) {
      p1[i] = p2[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
      if (i % 2 == 0) cin >> c, --c, ++p1[c];
      else            cin >> c, --c, ++p2[c];
    }

    for (int i = 0; i < CARDS; ++i) {
      p1_perfect += p1[i] / 3, p1[i] = p1[i] % 3;
      p2_perfect += p2[i] / 3, p2[i] = p2[i] % 3;
    }

    p1_common = max_common(p1);
    p2_common = max_common(p2);

    if (p1_perfect != p2_perfect) {
      if (p1_perfect > p2_perfect) {
        cout << "1" << endl;
      }
      else {
        cout << "2" << endl;
      }
    }
    else {
      if (p1_common != p2_common) {
        if (p1_common > p2_common) {
          cout << "1" << endl;
        }
        else {
          cout << "2" << endl;
        }
      }
      else cout << "0" << endl;
    }

    cin >> N;
  }
  return 0;
}