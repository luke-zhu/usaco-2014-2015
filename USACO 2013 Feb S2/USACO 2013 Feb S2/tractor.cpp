#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, t_v, grid[500][500];

int floodfill(int i, int j, int d, int c_v) {
	if (visited[i][j]) {
		return 1000000000;
	}
	visited[i][j] = true;
	if (c_v == t_v) {
		return 0;
	}
	int min_path;
	min_path = min(floodfill(i - 1, j, abs(grid[i - 1][j] - grid[i][j]), c_v + 1), floodfill(i + 1, j, abs(grid[i + 1][j] - grid[i][j]), c_v + 1));
	min_path = min(min_path, floodfill(i, j - 1, abs(grid[i][j - 1] - grid[i][j]), c_v + 1));
	min_path = min(min_path, floodfill(i, j + 1, abs(grid[i][j + 1] - grid[i][j]), c_v + 1));
	return d + min_path;
}

int main() {
	ofstream fout("tractor.out");
	ifstream fin("tractor.in");

	fin >> n;
	if (n % 2) {
		t_v = n * n / 2 + 1;
	}
	else {
		t_v = n * n / 2;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> grid[i][j];
		}
	}

	int shortest;
	shortest = 1000000000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int a = 0; a < n; ++a) {
				for (int b = 0; b < n; ++b) {
					visited[a][b] = false;
				}
			}
			shortest = min(shortest, floodfill(i, j, 0, 1));
		}
	}
	fout << shortest << "\n";
}