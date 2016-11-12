/*
ID: lukezhu1
PROG: humble
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int k, n, prime[100];
pii curr[100];
long long humble[100001];

int main() {
	ofstream fout("humble.out");
	ifstream fin("humble.in");

	fin >> k >> n;
	for (int i = 0; i < k; ++i) {
		fin >> prime[i];
		curr[i].first = prime[i];
		curr[i].second = 0;
	}
	//cout << "input cleared" << "\n";
	humble[0] = 1;
	for (int i = 1; i <= n; ++i) {
		humble[i] = (*min_element(curr, curr + k)).first;
		for (int j = 0; j < k; ++j) {
			if (curr[j].first == humble[i]) {
				curr[j].first = humble[++curr[j].second] * prime[j];
			}
		}
	}
	fout << humble[n] << "\n";
}