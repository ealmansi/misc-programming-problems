// 1540948 	5067 	Membership Management 	Accepted 	C++ 	0.036 	2014-09-10 21:02:58
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=3068

#include <iostream>
#include <cstdio>
#include <map>
#include <sstream>
#include <cmath>
#include <vector>
#include <list>
#include <set>
using namespace std;
typedef list <int> li;
typedef vector <int> vi;
typedef set <int> si;
typedef map <string, vector<string> > msvs;
typedef map <string, set<string> > msss;

#define forr(i,d,h) for (int i = (d); i < (h); i++)

int n;
string descr;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

msvs dicc;
msss memoria;

#define all(c) (c).begin(), (c).end()

set<string>& calcular(string& group)
{
	if (memoria.find(group) == memoria.end())
	{
		//cout << group << endl;
		memoria.insert(make_pair(group, set<string>()));
		
		vector<string>::iterator it;
		for (it = dicc[group].begin(); it != dicc[group].end(); ++it)
		{
			msvs::iterator submembers = dicc.find(*it);
			if (submembers == dicc.end()) memoria[group].insert(*it);
			else memoria[group].insert(all(calcular(*it)));
		}
	}
	return memoria[group];
}

int main()
{
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		
		dicc.clear();
		memoria.clear();
		
		string grupo0;
		forr(i, 0, n)
		{
			cin >> descr;
			vector<string> group, members;
			split(descr,':', group);
			split(group[1], ',', members);
			if (not members.empty()) members[members.size() - 1] = members[members.size() - 1].substr(0, members[members.size() - 1].size() - 1);
			if (i == 0) grupo0 = group[0];
			dicc.insert(make_pair(group[0], members));
		}
		//calcular(grupo0).size();
		cout << calcular(grupo0).size() << endl;
	}
	return 0;
}
