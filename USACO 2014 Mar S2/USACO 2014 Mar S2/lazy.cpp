#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int grid[400][400], grass[400][400];

int main() {
	ofstream fout("lazy.out");
	ifstream fin("lazy.in");

	int n, k;
	fin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int a = 0; a < n; ++a) {
				for (int b = 0; b < n; ++b) {
					if (abs(i - a) + abs(j - b) <= k) {
						grass[a][b] += grid[i][j];
					}
				}
			}
		}
	}
	int max_grass;
	max_grass = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			max_grass = max(max_grass, grass[i][j]);
		}
	}
	fout << max_grass << "\n";
}