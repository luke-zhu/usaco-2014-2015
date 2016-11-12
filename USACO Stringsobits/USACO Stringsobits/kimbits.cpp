/*
ID: lukezhu1
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

long long n, l, i, dp[32][32];

int main() {
	ofstream cout("kimbits.out");
	ifstream cin("kimbits.in");

	cin >> n >> l >> i;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	long long b = i;
	for (int i = 1; i <= n; ++i) {
		if (l == 0) {
			cout << 0;
			continue;
		}
		long long x = 0;
		for (int j = 0; j <= l; ++j) {
			x += dp[n - i][j];
		}
		if (b > x) {
			cout << 1;
			--l;
			b -= x;
		}
		else {
			cout << 0;
		}
	}
	cout << "\n";
}