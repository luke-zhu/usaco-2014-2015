#include <iostream>
#include <fstream>

using namespace std;

int n, m, s[10], area, dp[100000];

int main() {
	ofstream fout("tilechng.out");
	ifstream fin("tilechng.in");

	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		fin >> s[i];
		area += s[i] * s[i];
	}

	
	for (int i = 0; i < n; ++i) {
		for (int i = 1; i < s[i]; ++i) {}
	}
}