#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream cin("bbreeds.in");
	ofstream cout("bbreeds.out");

	string s;
	cin >> s;

	vector<int> dp[1001];


	for (int i = 0; i <= s.length(); ++i) {
		for (int j = 0; j < 1001; ++j) {
			dp[i].push_back(0);
			//cout << dp[i][j] << " ";
		}
		//cout << "\n";
	}

	dp[0][500] = 1;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			for (int j = 0; j < 1000; ++j) {
				dp[i + 1][j + 1] += dp[i][j];
			}
		}
		else {
			for (int j = 1; j < 1001; ++j) {
				dp[i + 1][j - 1] += dp[i][j];
			}
		}
		for (int j = 0; j < 1001; ++j) {
			dp[i + 1][j] += dp[i][j];
		}
	}

	cout << dp[s.length()][500] % 2012 << "\n";
}