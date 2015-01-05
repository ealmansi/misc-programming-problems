// Problem: Bitmap
/*
12320248	2014-09-07 05:04:19	emilio	Bitmap	accepted	 edit  run	3.43	3.0M	 C++ 4.3.2
http://www.spoj.com/problems/BITMAP/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cstdlib>

#define INF 1e9
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

#define MAX_N 182
#define MAX_M 182

using namespace std;

typedef pair<int, int> pii;

int M[MAX_N][MAX_M];
int D[MAX_N][MAX_M];
int n, m;

int di[4] = {0, -1, 0, 1};
int dj[4] = {-1, 0, 1, 0};

struct node
{
	node(int i, int j, int d) : i(i), j(j), d(d) {}
	int i, j, d;
};

void bfs(int i, int j)
{
	queue<node> q;
	
	for (int k = 0; k < 4; ++k)
		if (0 <= i + di[k] && i + di[k] < n && 0 <= j + dj[k] && j + dj[k] < m && M[i + di[k]][j + dj[k]] == 0)
			q.push(node(i + di[k], j + dj[k], 1));
	
	while(!q.empty())
	{
		node v = q.front(); q.pop();

		if (v.d < D[v.i][v.j])
		{
			D[v.i][v.j] = v.d;
			for (int k = 0; k < 4; ++k)
				if (0 <= v.i + di[k] && v.i + di[k] < n && 0 <= v.j + dj[k] && v.j + dj[k] < m && M[v.i + di[k]][v.j + dj[k]] == 0)
					q.push(node(v.i + di[k], v.j + dj[k], v.d + 1));
		}
	}
}

int main()
{
	int t;
	cin >> t;
	
	while(t > 0)
	{
		cin >> n >> m;
		
		char c;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> c;
				M[i][j] = c - '0';
			}
		}
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				D[i][j] = ((M[i][j] == 0) ? INF : 0);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if (M[i][j] == 1) bfs(i,j);
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cout << D[i][j];
				if (j < m - 1) cout << " ";
			}
			cout << endl;
		}
	
		t--;
	}
	
	return 0;
}