#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m, cow[5000], umbrella[100001], cost;

int main() {
	ofstream fout("umbrella.out");
	ifstream fin("umbrella.in");

	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		fin >> cow[i];
	}
	for (int i = 1; i <= m; ++i) {
		fin >> umbrella[i];
	}

	sort(cow, cow + n);
	cost = umbrella[m];
	for (int i = 0; i < n; ++i) {

	}
}