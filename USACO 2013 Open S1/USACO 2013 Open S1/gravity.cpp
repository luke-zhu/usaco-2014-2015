#include <iostream>
#include <fstream>

using namespace std;

int n, m, num[501][501], c[2], d[2];
char grid[501][501];


void dfs(int r, int c, int num_flips, int reversed) {
	// cout << r << " " << c << " ";
	bool fall;
	fall = true;
	if (reversed % 2) {
		for (int i = r; i > 0; --i) {
			if (grid[i - 1][c] == '#') {
				r = i;
				fall = false;
				break;
			}
			if (grid[i - 1][c] == 'D') {
				num[i - 1][c] = num_flips;
			}
		}
		if (fall) {
			// cout << "\n";
			return;
		}
	}
	else {
		for (int i = r; i < n - 1; ++i) {
			if (grid[i + 1][c] == '#') {
				r = i;
				fall = false;
				break;
			}
			if (grid[i + 1][c] == 'D') {
				num[i + 1][c] = num_flips;
			}
		}
		if (fall) {
			// cout << "\n";
			return;
		}
	}
	// cout << r << " " << c << "\n";
	if (num_flips >= num[r][c]) {
		return;
	}
	num[r][c] = num_flips;
	if (grid[r][c] == 'D') {
		return;
	}
	if (c != 0 && grid[r][c - 1] != '#') {
		dfs(r, c - 1, num_flips, reversed);
	}
	if (c + 1 != n && grid[r][c + 1] != '#') {
		dfs(r, c + 1, num_flips, reversed);
	}
	dfs(r, c, num_flips + 1, reversed + 1);
}

int main() {
	ofstream fout("gravity.out");
	ifstream fin("gravity.in");

	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			fin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 'C') {
				c[0] = i;
				c[1] = j;
			}
			if (grid[i][j] == 'D') {
				d[0] = i;
				d[1] = j;
			}
			num[i][j] = 1000000;
		}
	}
	cout << "Clear\n";
	dfs(c[0], c[1], 0, 0);
	if (num[d[0]][d[1]] == 1000000) {
		fout << -1 << "\n";
		return 0;
	}
	fout << num[d[0]][d[1]] << "\n";
}