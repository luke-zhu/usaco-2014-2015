#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m, t[10000], dp[10000], constraint[10000][10000];

int main() {
	ofstream fout("msched.out");
	ifstream fin("msched.in");

	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		fin >> t[i];
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		constraint[a][b] = 1;
	}
	for (int i = 0; i < n; ++i) {
		bool constrained;
		constrained = false;
		for (int j = 0; j < n; ++j) {
			if (constraint[j][i] == 1) {
				constrained = true;
				break;
			}
		}
		if (constrained) {
			continue;
		}
		for (int j = 0; j < n; ++j) {
			if (constraint[i][j]) {

			}
		}
	}
}