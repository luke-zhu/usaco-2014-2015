#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int checkpoint[100000][2];

int main() {
	ofstream fout("marathon.out");
	ifstream fin("marathon.in");

	int n;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> checkpoint[i][0] >> checkpoint[i][1];
	}

	int comp_d;
	comp_d = 0;
	for (int i = 1; i < n; ++i) {
		comp_d += abs(checkpoint[i][0] - checkpoint[i - 1][0]) + abs(checkpoint[i][1] - checkpoint[i - 1][1]);
	}

	int min_d;
	min_d = comp_d;
	for (int i = 1; i < n - 1; ++i) {
		int d;
		d = comp_d + abs(checkpoint[i + 1][0] - checkpoint[i - 1][0]) + abs(checkpoint[i + 1][1] - checkpoint[i - 1][1]);
		d -= abs(checkpoint[i][0] - checkpoint[i - 1][0]) + abs(checkpoint[i][1] - checkpoint[i - 1][1]);
		d -= abs(checkpoint[i][0] - checkpoint[i + 1][0]) + abs(checkpoint[i][1] - checkpoint[i + 1][1]);
		min_d = min(min_d, d);
	}
	fout << min_d << "\n";
}