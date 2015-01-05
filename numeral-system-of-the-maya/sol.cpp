// Problem: Numeral System Of The Maya
// 12320335	2014-09-07 05:26:08	emilio	Numeral System of the Maya	accepted	 edit  run	0.01	2.8M	 C++ 4.3.2
// http://www.spoj.com/problems/MAYA/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cstdlib>

using namespace std;

int main(){
		
	unsigned long long len;
	string line;

	while(true)
	{
		cin >> len; getline(cin, line);
		if(len == 0) break;
		
		unsigned long long digits[7] = { 0 };
		
		for (int i = len - 1; i >= 0; i--)
		{
			getline(cin, line);
			digits[i] = 0;
			for (unsigned int j = 0; j < line.size(); j++)
			{
				if(line[j] == '.') digits[i] += 1;
				else if(line[j] == '-') digits[i] += 5;
			}
		}
		
		unsigned long long res = 0;
		res += digits[0];
		res += (digits[1] * 20ul);
		res += (digits[2] * 360ul);
		res += (digits[3] * 360ul * 20ul);
		res += (digits[4] * 360ul * 20ul * 20ul);
		res += (digits[5] * 360ul * 20ul * 20ul * 20ul);
		res += (digits[6] * 360ul * 20ul * 20ul * 20ul * 20ul);
		cout << res << endl;
	}
	
	return 0;
}

