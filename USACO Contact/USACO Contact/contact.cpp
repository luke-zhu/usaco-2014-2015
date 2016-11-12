/*
ID: lukezhu1
PROG: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

string s;
vector < string > fre[200001];

int main()
{
	ofstream fout("contact.out");
	ifstream fin("contact.in");
	int A, B, N;
	fin >> A >> B >> N;
	string temp;
	while (fin >> temp)
		s += temp;
	for (int i = A; i <= B; i++)
	{
		map <string, int> m;
		map <string, int>::iterator it;
		if (s.size() < i) continue;
		for (int j = 0; j <= s.size() - i; j++) {
			m[s.substr(j, i)]++;
		}
		for (it = m.begin(); it != m.end(); it++) {
			temp = (*it).first;
			int cnt = (*it).second;
			if (cnt > 0) fre[cnt].push_back(temp);
		}
	}
	int cnt = 0;
	for (int i = 200000; i > 0; i--) {
		if (fre[i].size()) {
			fout << i << endl;
			int j;
			for (j = 0; j < fre[i].size(); j++) {
				if (j % 6 != 0) fout << " ";
				fout << fre[i][j];
				if (j % 6 == 5) fout << endl;
			}
			if (j % 6 != 0) fout << endl;
			cnt++;
			if (cnt == N) break;
		}
	}
}