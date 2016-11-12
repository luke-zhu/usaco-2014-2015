#include <iostream>
#include <fstream>

using namespace std;


char grid[102][102];
int n, cow[102][102], human[102][102];

void human_fill(int i, int j, char color, int region) {
	if (i == 0 || j == 0 || i > n || j > n || human[i][j] != 0) {
		return;
	}
	if (grid[i][j] == color) {
		//cout << 1 << "\n";
		human[i][j] = region;
		human_fill(i - 1, j, color, region);
		human_fill(i + 1, j, color, region);
		human_fill(i, j - 1, color, region);
		human_fill(i, j + 1, color, region);
	}
}

void cow_fill(int i, int j, char color, int region) {
	if (i == 0 || j == 0 || i > n || j > n || cow[i][j] != 0) {
		return;
	}
	if (grid[i][j] == color) {
		cow[i][j] = region;
		cow_fill(i - 1, j, color, region);
		cow_fill(i + 1, j, color, region);
		cow_fill(i, j - 1, color, region);
		cow_fill(i, j + 1, color, region);
	}
}

int main() {
	ofstream fout("cowart.out");
	ifstream fin("cowart.in");

	fin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			fin >> grid[i][j];
		}
	}

	int human_reg;
	human_reg = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (human[i][j] == 0) {
				++human_reg;
				human_fill(i, j, grid[i][j], human_reg);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (grid[i][j] == 'G') {
				grid[i][j] = 'R';
			}
		}
	}
	int cow_reg;
	cow_reg = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cow[i][j] == 0) {
				++cow_reg;
				cow_fill(i, j, grid[i][j], cow_reg);
			}
		}
	}
	fout << human_reg << " " << cow_reg << "\n";
}