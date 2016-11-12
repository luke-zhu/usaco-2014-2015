#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int n;
array < array < pair < char, bool >, 100 >, 100 > grid;

void flood_fill(int x, int y, char color) {
	if (x < 0 || x >= n || y < 0 || y >= n) {
		return;
	}
	else if (grid[x][y].first != color) {
		return;
	}
	else if (grid[x][y].second) {

		return;
	}
	grid[x][y].second = true;
	flood_fill(x + 1, y, color);
	flood_fill(x, y + 1, color);
	flood_fill(x - 1, y, color);
	flood_fill(x, y - 1, color);
	return;
}

int main() {
	ofstream fout("cowart.out");
	ifstream fin("cowart.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> grid[i][j].first;
			grid[i][j].second = false;
		}
	}
	fin.close();

	int h_regions;
	h_regions = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!grid[i][j].second) {
				flood_fill(i, j, grid[i][j].first);
				++h_regions;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j].first == 'G') {
				grid[i][j].first = 'R';
			}
			grid[i][j].second = false;
		}
	}

	int c_regions;
	c_regions = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!grid[i][j].second) {
				flood_fill(i, j, grid[i][j].first);
				++c_regions;
			}
		}
	}
	cout << h_regions << " "<< c_regions << "\n";
}