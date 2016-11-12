/*
ID: lukezhu1
PROG: concom
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int n, percent[105][105], cont[105][105];

int main() {
	ofstream fout("concom.out");
	ifstream fin("concom.in");
	// condition 1
	for (int i = 1; i <= 100; ++i) {
		cont[i][i] = 1;
		percent[i][i] = 100;
	}
	// condition 2
	fin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, perc;
		fin >> a >> b >> perc;
		percent[a][b] = perc;
		if (perc > 50) {
			cont[a][b] = 1;
		}
	}
	//condition 3
	int change;
	change = 1;
	while (change) {
		change = 0;
		for (int i = 1; i <= 100; ++i) {
			for (int j = 1; j <= 100; ++j) {
				if (percent[i][j] < 50) {
					int perc;
					perc = 0;
					for (int k = 1; k <= 100; ++k) {
						if (cont[i][k]) {
							perc += percent[k][j];
						}
					}
					if (perc > 50 && !cont[i][j]) {
						//cout << perc << "\n";
						cont[i][j] = 1;
						++change;
					}
				}
			}
		}
	}

	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (i != j && cont[i][j]) {
				//cout << i << " " << j << "\n";
				fout << i << " " << j << "\n";
			}
		}
	}
}