/*
ID: lukezhu1
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	int n, res = 0, c1 = 0, c2 = 0, a[1000];

	ofstream fout("sort3.out");
	ifstream fin("sort3.in");

	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> a[i];
		if (a[i] == 1)
			++c1;
		else if (a[i] == 2)
			++c2;
	}

	for (int i = c1; i < n; i++) {
		if (a[i] == 1) {
			int t;
			t = 0;
			for (int j = 0; j < c1; j++) {
				if (a[j] == 2) {
					t = j;
					break;
				}
				else if (a[j] == 3) {
					t = j;
				}
			}
			swap(a[i], a[t]);
			++res;
		}
	}

	for (int i = c1 + c2; i < n; i++)
		if (a[i] == 2)
			++res;

	fout << res << "\n";
}