// Problem: Check The String Powers
// 12602724	2014-10-11 20:44:06	emilio	Check the string Powers	accepted	edit  run	0.01	2.8M	C++4.3.2
// http://www.spoj.com/problems/IITKWPCJ/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T;
int A_len, B_len;
char A[100005], B[100005];

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return min(a, b) / gcd(a, b) * max(a, b);
}

bool ok() {
	int L = lcm(A_len, B_len);
	for (int i = 0; i < 100000; ++i) {
		int index = rand() % L; 
		if (A[index % A_len] != B[index % B_len]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		scanf("%s %s\n", A, B);
		A_len = strlen(A), B_len = strlen(B);
		if (ok()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}