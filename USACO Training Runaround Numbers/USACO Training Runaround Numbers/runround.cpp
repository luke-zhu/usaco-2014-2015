/*
ID: lukezhu1
PROG: runround
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	ofstream fout("runround.out");
	ifstream fin("runround.in");

	int m;
	fin >> m;
	++m;

	while (true) {
		char str[9 + 3];
		sprintf(str, "%d", m);

		int frequency[10] = { 0 };

		int len = strlen(str);
		int currNumber = str[0] - '0';
		int currIndex = 0;
		bool flag;
		flag = true;
		for (int i = 0; i < len; i++) {
			currIndex = (currIndex + currNumber) % len;
			currNumber = str[currIndex] - '0';
			frequency[currNumber]++;
			if (!currNumber || frequency[currNumber] > 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			fout << m << "\n";
			break;
		}
		++m;
	}
}