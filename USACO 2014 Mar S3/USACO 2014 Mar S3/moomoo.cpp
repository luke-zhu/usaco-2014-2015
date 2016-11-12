#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int breed[20], volume[100], dp[100][100101];

int main() {
	ofstream fout("mooomoo.out");
	ifstream fin("mooomoo.in");

	int n, b;
	fin >> n >> b;
	for (int i = 0; i < b; ++i) {
		fin >> breed[i];
	}
	for (int i = 0; i < n; ++i) {
		fin >> volume[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < 100101; ++j) {
			dp[i][j] = 1000000000;
		}
	}

	int min_cows;
	min_cows = 0;
	if (volume[0] > 0) {
		for (int i = 0; i < volume[0]; ++i) {
			for (int j = 0; j < b; ++j) {
				dp[0][i + breed[j]] = min(dp[0][i + breed[j]], dp[0][i] + 1);
			}
		}
		if (dp[0][volume[0]] == 1000000000) {
			fout << -1 << "\n";
			return 0;
		}
		else {
			cout << dp[0][volume[0]];
			min_cows += dp[0][volume[0]];
		}
	}

	for (int a = 1; a < n; ++a) {
		if (volume[a] > volume[a - 1] + 1) {
			int cow;
			cow = volume[a] - max(volume[a - 1] - 1, 0);
			for (int i = 0; i < cow; ++i) {
				for (int j = 0; j < b; ++j) {
					dp[a][i + breed[j]] = min(dp[a][i + breed[j]], dp[a][i] + 1);
					//cout << dp[a][i] + 1 << "\n";
				}
			}
			if (dp[a][cow] == 1000000000) {
				fout << -1 << "\n";
				return 0;
			}
			else {
				//cout << dp[a][cow] << "\n";
				min_cows += dp[a][cow];
			}
		}
	}
	fout << min_cows << "\n";
}