/*
ID: lukezhu1
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int n, last[4221];
long long dp[4221];

int main() {
	ofstream cout("fact4.out");
	ifstream cin("fact4.in");

	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= 4220; ++i) {
		dp[i] = i * dp[i - 1];
		dp[i] %= 1000000000000000;
		while (dp[i] % 10 == 0) {
			dp[i] /= 10;
		}
		last[i] = dp[i] % 10;
	}
	cout << last[n] << "\n";
}