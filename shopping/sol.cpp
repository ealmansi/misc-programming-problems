// Problem: Shopping
// 12320362	2014-09-07 05:32:56	emilio	Shopping	accepted	 edit  run	0.00	2.8M	 C++ 4.3.2
// http://www.spoj.com/problems/SHOP/cstart=10

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cstdlib>

using namespace std;

struct node {
	node(int i, int j, int s, int d) : i(i), j(j), s(s), d(d) {}
	int i, j, s, d;
};

char shop[25][25];
bool visited[25][25];

int w, h;

int di[4] = {0, -1, 0, 1};
int dj[4] = {-1, 0, 1, 0};

int bfs(int is, int js)
{
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			visited[i][j] = false;

	queue<node> q;
	q.push(node(is, js, 0, 0));

	while(not q.empty())
	{
		node v = q.front(); q.pop();
		if (v.s > 0)
		{
			q.push(node(v.i, v.j, v.s - 1, v.d + 1));
		}
		else
		{
			for (int k = 0; k < 4; ++k)
			{
				if (0 <= v.i + di[k] && v.i + di[k] < h && 0 <= v.j + dj[k] && v.j + dj[k] < w)
				{
					if (shop[v.i + di[k]][v.j + dj[k]] == 'D')
						return v.d;

					if ('0' <= shop[v.i + di[k]][v.j + dj[k]] && shop[v.i + di[k]][v.j + dj[k]] <= '9')
					{
						if (not visited[v.i + di[k]][v.j + dj[k]])
						{
							q.push(node(v.i + di[k], v.j + dj[k], shop[v.i + di[k]][v.j + dj[k]] - '0', v.d));
							visited[v.i + di[k]][v.j + dj[k]] = true;
						}
					}
				}
			}
		}
	}
}

int main()
{
	while(true)
	{
		cin >> w >> h;
		if(w == 0 && h == 0) break;
		
		int is, js;
		
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				cin >> shop[i][j];
				if (shop[i][j] == 'S') is = i, js = j;
			}
		}
		
		cout << bfs(is, js) << endl;
	}
	
	return 0;
}
