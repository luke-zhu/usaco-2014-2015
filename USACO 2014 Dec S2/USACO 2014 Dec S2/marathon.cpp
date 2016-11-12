#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k, coord[500][2], dp[500][500], dist;

int main() {
	ofstream fout("marathon.out");
	ifstream fin("marathon.in");

	fin >> n >> k;
	for (int i = 0; i < n; ++i) {
		fin >> coord[i][0] >> coord[i][1];
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = 1000000;
		}
	}

	dp[0][0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int a = 0; a <= k - j && i + a < n; ++a) {
				dp[i + a + 1][j + a] = min(dp[i + a + 1][j + a], dp[i][j] + abs(coord[i + a + 1][0] - coord[i][0]) + abs(coord[i + a + 1][1] - coord[i][1]));
			}
		}
	}

	dist = 1000000;
	for (int i = 0; i <= k; ++i) {
		dist = min(dist, dp[n - 1][k]);
	}
	fout << dist << "\n";
}