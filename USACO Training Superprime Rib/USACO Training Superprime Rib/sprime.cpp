/*
ID: lukezhu1
PROB: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int digits[5] = { 1, 3, 5, 7, 9 };
vector < int > superprimes[8];

bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void superprime(int n) {
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < superprimes[n - 2].size(); ++j) {
			int next;
			next = 10 * superprimes[n - 2][j] + digits[i];
			if (is_prime(next)) {
				superprimes[n - 1].push_back(next);
			}
		}
	}
}

int main() {
	ofstream fout("sprime.out");
	ifstream fin("sprime.in");
	
	int n;
	fin >> n;

	superprimes[0].assign(4, 2);
	superprimes[0][1] = 3;
	superprimes[0][2] = 5;
	superprimes[0][3] = 7;
	for (int i = 2; i <= n; ++i) {
		superprime(i);
	}
	sort(superprimes[n - 1].begin(), superprimes[n - 1].end());
	for (int i = 0; i < superprimes[n - 1].size(); ++i) {
		fout << superprimes[n - 1][i] << "\n";
	}
}