#include <iostream>
#include <fstream>
#include <array>

using namespace std;
array < pair < int, int >, 100000 > patches;
array < int, 99999 > distances;

int main() {
	ofstream fout("lazy.out");
	ifstream fin("lazy.in");

	int n, k;
	fin >> n >> k;
	for (int i = 0; i < n; ++n) {
		int x, g;
		fin >> g >> x;
		patches[i] = pair < int, int >(x, g);
	}
	sort(patches.begin(), patches.end());

	for (int i = 0; i < n - 1; ++i) {
		distances[i] = patches[i + 1].first - patches[i].first;
	}

	for (int i = 0; i < n; ++i) {
		int cumulative;
		cumulative = 0;
		if (cumulative + distances[i] < 2 * k)
	}
}