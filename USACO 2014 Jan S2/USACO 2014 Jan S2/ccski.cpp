#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#define INF 1000000000;
using namespace std;

int m, n, elevation[500][500], waypoint[500][500], d[500][500];

void floodfill(int r, int c, int difficulty) {
	if (difficulty >= d[r][c]) {
		return;
	}
	d[r][c] = difficulty;
	if (r > 0) {
		floodfill(r - 1, c, max(difficulty, abs(elevation[r][c] - elevation[r - 1][c])));
	}
	if (r < m - 1) {
		floodfill(r + 1, c, max(difficulty, abs(elevation[r][c] - elevation[r + 1][c])));
	}
	if (c > 0) {
		floodfill(r, c - 1, max(difficulty, abs(elevation[r][c] - elevation[r][c - 1])));
	}
	if (c < n - 1) {
		floodfill(r, c + 1, max(difficulty, abs(elevation[r][c] - elevation[r][c + 1])));
	}
}

int main() {
	ofstream fout("ccski.out");
	ifstream fin("ccski.in");

	fin >> m >> n;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> elevation[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> waypoint[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (waypoint[i][j]) {
				floodfill(i, j, 0);
				int max_d;
				max_d = 0;
				for (int k = 0; k < m; ++k) {
					for (int l = 0; l < n; ++l) {
						if (waypoint[k][l]) {
							max_d = max(max_d, d[k][l]);
						}
					}
				}
				fout << max_d << "\n";
				return 0;
			}
		}
	}
}