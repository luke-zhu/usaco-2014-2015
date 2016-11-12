/*
ID: lukezhu1
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n, curr, stamp[100];
vector<int> dp(2010002, 202);

int main() {
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");
	
	fin >> k >> n;
	for (int i = 0; i < n; ++i) {
		fin >> stamp[i];
	}
	sort(stamp, stamp + n);
	dp[0] = 0;
	for (int i = 0; i <= stamp[n - 1] * k; ++i) {
		if (dp[i] > k) {
			//cout << i - 1 << "\n";
			fout << i - 1 << "\n";
			return 0;
		}
		for (int j = 0; j < n; ++j) {
			dp[i + stamp[j]] = min(dp[i + stamp[j]], dp[i] + 1);
		}
	}
	//cout << stamp[n - 1] * k << "\n";
	fout << stamp[n - 1] * k << "\n";
}