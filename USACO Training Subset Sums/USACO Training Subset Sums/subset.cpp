/*
ID: lukezhu1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

long long sums[800];

int main() {
	ofstream fout("subset.out");
	ifstream fin("subset.in");

	int n;
	fin >> n;
	if (n % 4 == 1 || n % 4 == 2) {
		fout << "0\n";
		return 0;
	}
	int sum;
	sum = n * (n + 1) / 2;

	sums[0] = 1; // see knapsack
	for (int i = 1; i <= n; ++i) { // Because the number of ways to get a certain sum = number of ways to get from subsum + i)
		for (int j = sum - i; j >= 0; --j) {// No repeats because i is the value being added
				sums[j + i] += sums[j];
		}
	}
	fout << sums[sum / 2] / 2 << "\n";
}
