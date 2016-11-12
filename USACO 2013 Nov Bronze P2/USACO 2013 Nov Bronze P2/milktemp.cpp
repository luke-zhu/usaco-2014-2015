#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("milktemp.out");
	ifstream fin("milktemp.in");

	pair < int, int > ranges[20000];
	int in_range[20000] = { 1 };

	int n, x, y, z;
	fin >> n >> x >> y >> z;
	for (int i = 0; i < n; ++i) {
		fin >> ranges[i].first >> ranges[i].second;
	}

	sort(ranges, ranges + n);

	for (int i = 0; i < n; ++i) {
		int temp;
		temp = ranges[i].first;

		if (temp)
	}
}