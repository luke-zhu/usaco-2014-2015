/*
ID: lukezhu1
PROG: inflate
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int dp[20000], weight[10000][2];// (points, minutes)

int main() {
	ofstream fout("inflate.out");
	ifstream fin("inflate.in");

	int m, n;
	fin >> m >> n;
	for (int i = 0; i < n; ++i) {
		fin >> weight[i][0] >> weight[i][1];
	}


	for (int i = 0; i <= 10000; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i + weight[j][1]] = max(dp[i + weight[j][1]], dp[i] + weight[j][0]);
		}
		//cout << i << "\n";
	}
	cout << dp[m] << "\n";
	fout << dp[m] << "\n";
}