#include <iostream>
#include <fstream>

using namespace std;

int grid[30][30], matrix[30][30][30][30];

int main() {
	ofstream fout("distant.out");
	ifstream fin("distant.in");

	int n, a, b;
	fin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			fin >> c;
			if (c == ')') {
				grid[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				for (int l = 0; l < n; ++l) {
					if (i != k || j != l) {
						matrix[i][j][k][l] = 1000000000;
					}
				}
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == grid[i + 1][j]) {
				matrix[i][j][i + 1][j] = a;
				matrix[i + 1][j][i][j] = a;
			}
			else {
				matrix[i][j][i + 1][j] = b;
				matrix[i + 1][j][i][j] = b;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (grid[i][j] == grid[i][j + 1]) {
				matrix[i][j][i][j + 1] = a;
				matrix[i][j + 1][i][j] = a;
			}
			else {
				matrix[i][j][i][j + 1] = b;
				matrix[i][j + 1][i][j] = b;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			fin >> c;
			if (c == ')') {
				grid[i][j] = 1;
			}
		}
	}

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < n; ++k) {
						for (int l = 0; l < n; ++l) {
							if (matrix[i][j][a][b] + matrix[a][b][k][l] < matrix[i][j][k][l]) {
								matrix[i][j][k][l] = matrix[i][j][a][b] + matrix[a][b][k][l];
							}
						}
					}
				}
			}
		}
	}
	int longest;
	longest = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				for (int l = 0; l < n; ++l) {
					if (matrix[i][j][k][l] > longest) {
						longest = matrix[i][j][k][l];
					}
				}
			}
		}
	}
	//cout << longest << "\n";
	fout << longest << "\n";
}