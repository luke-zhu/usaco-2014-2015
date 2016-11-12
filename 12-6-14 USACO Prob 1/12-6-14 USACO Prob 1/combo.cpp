#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");

	int n;
	fin >> n;
	int fjohn[3], master[3];
	fin >> fjohn[0] >> fjohn[1] >> fjohn[2];
	fin >> master[0] >> master[1] >> master[2];

	int count;
	count = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (abs(i - fjohn[0]) <= 2 || abs(i - fjohn[0]) >= n - 2) {
					if (abs(j - fjohn[1]) <= 2 || abs(j - fjohn[1]) >= n - 2) {
						if (abs(k - fjohn[2]) <= 2 || abs(k - fjohn[2]) >= n - 2) {
							++count;
							continue;
						}
					}
				}
				if (abs(i - master[0]) <= 2 || abs(i - master[0]) >= n - 2) {
					if (abs(j - master[1]) <= 2 || abs(j - master[1]) >= n - 2) {
						if (abs(k - master[2]) <= 2 || abs(k - master[2]) >= n - 2) {
							++count;
						}
					}
				}
			}
		}
	}
	cout << count << "\n";
}