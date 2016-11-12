#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int grid[51][51];
int n, m;
int spot;

void fill(int i, int j) {
	if (grid[i][j] != -1) {
		return;
	}
	grid[i][j] = spot;
	fill(i - 1, j);
	fill(i + 1, j);
	fill(i, j - 1);
	fill(i, j + 1);
}

int main() {
	ofstream fout("pageant.out");
	ifstream fin("pageant.in");

	fin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char c;
			fin >> c;
			if (c == 'X') {
				grid[i][j] = -1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] == -1){
				++spot;
				fill(i, j);
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << grid[i][j];
		}
		cout << "\n";
	}
	
	int min_12, min_23, min_13;
	min_12 = n*m, min_23 = n*m, min_13 = n*m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] == 1) {
				for (int k = 1; k <= n; ++k) {
					for (int l = 1; l <= m; ++l) {
						if (grid[k][l] == 2) {
							if (abs(k - i) + abs(l - j) < min_12) {
								min_12 = abs(k - i) + abs(l - j);
							}
						}
						else if (grid[k][l] == 3) {
							if (abs(k - i) + abs(l - j) < min_13) {
								min_13 = abs(k - i) + abs(l - j);
							}
						}
					}
				}
			}
			if (grid[i][j] == 2) {
				for (int k = 1; k <= n; ++k) {
					for (int l = 1; l <= m; ++l) {
						if (grid[k][l] == 3) {
							if (abs(k - i) + abs(l - j) < min_23) {
								min_23 = abs(k - i) + abs(l - j);
							}
						}
					}
				}
			}
		}
	}
	cout << min_12 << " " << min_13 << " " << min_23 << "\n";
	cout << min(min_12 + min_13, min(min_12 + min_23, min_13 + min_23)) << "\n";
}