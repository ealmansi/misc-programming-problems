// 1540952 	4188 	Quick answer 	Accepted 	C++ 	0.076 	2014-09-10 21:07:40
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2189

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;
typedef set<int> si;

#define MAXN 10005
int N;

int p[MAXN], r[MAXN];
si hs[MAXN];

#define all(c) (c).begin(), (c).end()

void make(int u)
{
	hs[u].clear();
	p[u] = u;
	hs[u].insert(u);
	
	r[u] = 0;
}

int find(int u)
{
	if (u != p[u])
	{
		hs[p[u]].erase(u);
		p[u] = find(p[u]);
		hs[p[u]].insert(u);
	}
	return p[u];
}

void join(int u, int v)
{
	int ur = find(u), vr = find(v);
	if (ur == vr) return;
	
	if (r[ur] < r[vr])
	{
		hs[p[ur]].erase(ur);
		p[ur] = vr;
		hs[p[ur]].insert(ur);
	}
	else if (r[vr] < r[ur])
	{
		hs[p[vr]].erase(vr);
		p[vr] = ur;
		hs[p[vr]].insert(vr);
	}
	else
	{
		hs[p[vr]].erase(vr);
		p[vr] = ur;
		hs[p[vr]].insert(vr);
		++r[ur];
	}
}

void chau(int u)
{
	if (u == p[u] and (hs[u].size() == 1)) return;
	
	if (u != p[u])
	{
		si::iterator it;
		for (it = hs[u].begin(); it != hs[u].end(); ++it) if (*it != u)
		{
			int h = *it;
			p[h] = p[u];
			hs[p[u]].insert(h);
		}
		hs[p[u]].erase(u);
		make(u);
	}
	else if (hs[u].size() > 1)
	{
		hs[p[u]].erase(u);
		int nuevo_papa = *(hs[u].begin());
		si::iterator it;
		for (it = hs[u].begin(); it != hs[u].end(); ++it) if (*it != u)
		{
			int h = *it;
			p[h] = nuevo_papa;
			hs[nuevo_papa].insert(h);
		}
		make(u);
	}
}

int main(){

	char c; int u, v;
	while (cin >> N)
	{
		for (int i = 0; i < N; i++)
			make(i);
		int yes = 0, no = 0;
		while (true)
		{
			cin >> c;
			if (c == 'e') break;
			else if (c == 'c')
			{
				cin >> u >> v; --u; --v;
				join(u, v);
			}
			else if (c == 'd')
			{
				cin >> u; --u;
				chau(u);
			}
			else if (c == 'q')
			{
				cin >> u >> v; --u; --v;
				if (find(u) == find(v)) ++yes;
				else ++no;
			}
		}
		cout << yes << " , " << no << endl;
	}
	
	return 0;
}
