#include <iostream>
#include <fstream>

using namespace std;

char grid[50][50];
int clued[50][50];

int main() {
	ofstream fout("crosswords.out");
	ifstream fin("crosswords.in");

	int n, m;
	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			fin >> grid[i][j];
		}
	}

	int count;
	count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i < n - 2 && (i == 0 || grid[i - 1][j] == '#')) {
				//cout << i + 1 << " " << j + 1 << "\n";
				if (grid[i][j] == '.' && grid[i + 1][j] == '.' && grid[i + 2][j] == '.') {
					clued[i][j] = 1;
					++count;
					continue;
					//cout << 'v' << "\n";
				}
			}
			if (j < m - 2 && (j == 0 || grid[i][j - 1] == '#')) {
				//cout << i + 1 << " " << j + 1 << "\n";
				if (grid[i][j] == '.' && grid[i][j + 1] == '.' && grid[i][j + 2] == '.') {
					clued[i][j] = 1;
					++count;
					//cout << 'h' << "\n";
				}
			}
		}
	}

	fout << count << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (clued[i][j]) {
				fout << i + 1 << " " << j + 1 << "\n";
			}
		}
	}
}