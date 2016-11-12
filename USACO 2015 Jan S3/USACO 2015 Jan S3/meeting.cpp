#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m, b[100][100], e[100][100];

int main() {
	ofstream fout("meeting.out");
	ifstream fin("meeting.in");

	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				b[i][j] = 1000000;
				e[i][j] = 1000000;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		int x, y;
		fin >> x >> y;
		--x, --y;
		fin >> b[x][y];
		fin >> e[x][y];
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (b[i][j] > b[i][k] + b[k][j]) {
					b[i][j] = b[i][k] + b[k][j];
				}
				if (e[i][j] > e[i][k] + e[k][j]) {
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}

	int ans = 1000000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (b[0][i] + b[i][n - 1] == e[0][j] + e[j][n - 1]) {
				ans = min(ans, b[0][i] + b[i][n - 1]);
			}
		}
	}
	fout << ans << "\n";
}