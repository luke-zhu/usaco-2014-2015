#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int cows[20000][2], sorted[40000];

int main() {
	ofstream fout("milktemp.out");
	ifstream fin("milktemp.in");

	int n, x, y, z;
	fin >> n >> x >> y >> z;
	for (int i = 0; i < n; ++i) {
		fin >> cows[i][0] >> cows[i][1];
		sorted[2 * i - 1] = cows[i][0];
		sorted[2 * i] = cows[i][1];
	}
	sort(sorted, sorted + 2 * n - 1);

	int max_milk;
	max_milk = 0;
	for (int i = 0; i < 2 * n - 1; ++i) {
		int milk;
		milk = 0;
		for (int j = 0; j < n; ++j) {
			if (sorted[i] < cows[j][0]) {
				milk += x;
			}
			else if (sorted[i] > cows[j][1]) {
				milk += z;
			}
			else {
				milk += y;
			}
		}
		if (milk > max_milk) {
			max_milk = milk;
		}
	}
	cout << max_milk << "\n";
}