// 12325576	2014-09-08 00:23:15	emilio	Counting Rabbits	accepted	 edit  run	0.01	2.6M	 C++ 4.3.2
// http://www.spoj.com/problems/RABBIT1/

#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned long long ull;

ull C, N, M, box_size;

void mat_mul(ull dst[2][2], ull left[2][2], ull right[2][2])
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				if (k == 0) dst[i][j] = (left[i][k] * right[k][j]) % box_size;
				else dst[i][j] = (dst[i][j] + (left[i][k] * right[k][j]) % box_size) % box_size;
}

void mat_to_the_power(ull mat[2][2], int N)
{
	if(N == 1) return;

	ull aux[2][2], aux2[2][2];
	aux[0][0] = aux2[0][0] = mat[0][0]; aux[0][1] = aux2[0][1] = mat[0][1];
	aux[1][0] = aux2[1][0] = mat[1][0]; aux[1][1] = aux2[1][1] = mat[1][1];
	switch(N % 2)
	{
	case 0:
		mat_to_the_power(aux, N/2);
		mat_mul(mat, aux, aux);
		break;
	case 1:
		mat_to_the_power(aux, N - 1);
		mat_mul(mat, aux, aux2);
		break;
	}
}

int main(int argc, char const *argv[])
{
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		cin >> N >> M;
		box_size = 1<<M;
		ull mat[2][2] = {{1, 1}, {1, 0}};
		mat_to_the_power(mat, N);
		cout << mat[0][0] << endl;
	}

	return 0;
}