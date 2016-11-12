/*
ID: lukezhu1
PROG: money
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int v, n, coin[25];
long long dp[10001][25];

int main() {
	ofstream fout("money.out");
	ifstream fin("money.in");

	fin >> v >> n;
	for (int i = 0; i < v; ++i) {
		fin >> coin[i];
	}
	for (int i = 0; i <= n / coin[0]; ++i) {
		dp[i * coin[0]][0] = 1;
	}
	for (int i = 1; i < v; ++i) {
		for (int j = 0; j <= n / coin[i]; ++j) {
			for (int k = 0; k <= n; ++k) {
				if (k + j * coin[i] <= 10000)
					dp[k + j * coin[i]][i] += dp[k][i - 1];
			}
		}
	}
	/*
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j <= n; ++j) {
			cout << i << " " << j << " " << dp[j][i] << "\n";
		}
	}
	*/
	fout << dp[n][v - 1] << "\n";
}