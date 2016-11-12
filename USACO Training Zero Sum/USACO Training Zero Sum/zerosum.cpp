/*
ID: lukezhu1
PROG: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;
string sequence[10][20000];
int dp[10][20000], curr[10][20000];

int main() {
	ofstream fout("zerosum.out");
	ifstream fin("zerosum.in");

	int n;
	fin >> n;
	sequence[1][1] = "1";
	dp[1][1] = 1;
	curr[1][1] = 1;
	for (int i = 2; i <= 9; ++i) {
		for (int j = 1; j <= pow(3, i - 1); ++j) {
			sequence[i][3 * j - 2] = sequence[i - 1][j] + " " + (char)(i + 48);
			if (curr[i - 1][j] > 0) {
				dp[i][3 * j - 2] = dp[i - 1][j] + 9 * curr[i - 1][j] + i;
				curr[i][3 * j - 2] = 10 * curr[i - 1][j] + i;
			}
			else {
				dp[i][3 * j - 2] = dp[i - 1][j] + 9 * curr[i - 1][j] - i;
				curr[i][3 * j - 2] = 10 * curr[i - 1][j] - i;
			}
			sequence[i][3 * j - 1] = sequence[i - 1][j] + "+" + (char)(i + 48);
			dp[i][3 * j - 1] = dp[i - 1][j] + i;
			curr[i][3 * j - 1] = i;
			sequence[i][3 * j] = sequence[i - 1][j] + "-" + (char)(i + 48);
			dp[i][3 * j] = dp[i - 1][j] - i;
			curr[i][3 * j] = -i;
		}
	}
	for (int i = 1; i <= pow(3, n - 1); ++i) {
		if (!dp[n][i])
		fout << sequence[n][i] << "\n";
	}
}