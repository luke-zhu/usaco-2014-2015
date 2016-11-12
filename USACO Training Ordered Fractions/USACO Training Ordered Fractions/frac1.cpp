/*
ID: lukezhu1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	while (b > 0) {
		int r;
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool decimal_compare(pair < int, int > p1, pair < int, int > p2) {
	double r1, r2;
	r1 = (double)p1.first / p1.second;
	r2 = (double)p2.first / p2.second;
	return r1 < r2;
}

int main() {
	ofstream fout("frac1.out");
	ifstream fin("frac1.in");

	int n;
	fin >> n;

	vector < pair < int, int > > fractions;
	fractions.push_back(pair < int, int >(0, 1));
	fractions.push_back(pair < int, int >(1, 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (gcd(i, j) == 1) {
				fractions.push_back(pair < int, int >(j, i));
			}
		}
	}
	sort(fractions.begin(), fractions.end(), decimal_compare);

	for (int i = 0; i < fractions.size(); ++i) {
		fout << fractions[i].first << "/" << fractions[i].second << "\n";
	}
}