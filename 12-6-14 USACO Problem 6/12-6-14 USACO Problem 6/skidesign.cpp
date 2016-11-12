#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");

	int n;
	fin >> n;
	int height[1000];
	for (int i = 0; i < n; ++i) {
		fin >> height[i];
	}

	int min_cost;
	min_cost = 10000000;
	for (int i = 0; i <= 83; ++i) {
		int cost;
		cost = 0;
		for (int j = 0; j < n; ++j) {
			if (height[j] < i) {
				cost += (i - height[j]) * (i - height[j]);
			}
			else if (height[j] > i + 17) {
				cost += (height[j] - i - 17) * (height[j] - i - 17);
			}
		}
		if (cost < min_cost) {
			min_cost = cost;
		}
	}
	fout << min_cost << "\n";
}