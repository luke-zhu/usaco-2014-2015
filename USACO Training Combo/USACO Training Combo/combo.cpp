/*
ID: lukezhu1
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");

	int n, f[3], m[3];
	fin >> n >> f[0] >> f[1] >> f[2] >> m[0] >> m[1] >> m[2];

	int num_combos;
	num_combos = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (abs(f[0] - i) <= 2 || n - abs(f[0] - i) <= 2) {
					if (abs(f[1] - j) <= 2 || n - abs(f[1] - j) <= 2) {
						if (abs(f[2] - k) <= 2 || n - abs(f[2] - k) <= 2) {
							//cout << i << " " << j << " " << k << "\n";
							++num_combos;
							continue;
						}
					}
				}
				if (abs(m[0] - i) <= 2 || n - abs(m[0] - i) <= 2) {
						if (abs(m[1] - j) <= 2 || n - abs(m[1] - j) <= 2) {
							if (abs(m[2] - k) <= 2 || n - abs(m[2] - k) <= 2) {
								//cout << i << " " << j << " " << k << "\n";
								++num_combos;
							}
					}
				}
			}
		}
	}
	fout << num_combos << "\n";
}