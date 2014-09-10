// 1540954 	4187 	Build Your Home 	Accepted 	C++ 	0.003 	2014-09-10 21:09:25
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2188

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int k;
vector<long double> x, y;

int main(){
	
	while (true)
	{
		cin >> k;
		if (k == 0) break;
		x.resize(k); y.resize(k);
		for (int i = 0; i < k; i++)
		{
			cin >> x[i] >> y[i];
			//cout << x[i] << " " << y[i] << endl;
		}
		
		if (k < 3)
		{
			cout << 0 << endl;
		}
		else
		{
			long double area = 0;
			for (int i = 0; i < k; i++)
				area += x[i] * y[(i + 1)%k] - x[(i + 1)%k] * y[i];
			cout << round(abs(area/2)) << endl;
		}
	}
	
	return 0;
}
