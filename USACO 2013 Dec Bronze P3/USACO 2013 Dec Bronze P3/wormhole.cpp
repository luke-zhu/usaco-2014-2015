#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <map>

using namespace std;

int n;
array < pair < int, int >, 3 > coord;
map < pair < int, int >, pair < int, int > > paths;
map < pair < int, int >, pair < int, int > > wormholes;

int main() {
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> coord[i].second >> coord[i].first;
	}
	sort(coord.begin(), coord.end());

	for (int i = 0; i < n - 1; ++i) {
		if (coord[i].first == coord[i + 1].first) {
			paths[coord[i]] = coord[i + 1];
		}
	}


}