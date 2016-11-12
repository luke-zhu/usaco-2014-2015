#include <iostream>
#include <fstream>

using namespace std;

int	pairs[15][15], paths[15][15];

int main() {
	ofstream fout("assign.out");
	ifstream fin("assign.in");

	int n, k;
	fin >> n >> k;
	for (int i = 0; i < k; ++i) {
		char c;
		int x, y;
		fin >> c >> x >> y;
		if (c == 'S') {
			pairs[x][y] = 1;
			pairs[y][x] = 1;
		}
		else {
			pairs[x][y] = -1;
			pairs[y][x] = -1;
		}
	}

	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << pairs[i][j] << " ";
		}
		cout << "\n";
	}
	*/

}