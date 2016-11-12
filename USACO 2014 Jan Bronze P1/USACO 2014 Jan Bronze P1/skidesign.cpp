#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");

	int n;
	fin >> n;
	array < int, 1000 > heights;
	for (int i = 0; i < n; ++i) {
		fin >> heights[i];
	}
	fin.close;

	int min_cost;
	min_cost = 2500000;
	for (int i = 0; i <= 83; ++i) {
		int cost;
		cost = 0;
		for (int j = 0; j < n; ++j) {
			if (heights[j] < i) {
				cost += (i - heights[j]) * (i - heights[j]);
			}
			else if (heights[j] > i + 17) {
				cost += (heights[j] - i - 17) * (heights[j] - i - 17);
			}
		}
		min_cost = min(min_cost, cost);
	}
	cout << min_cost << "\n";
	fout.close();
}