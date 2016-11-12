/*
ID: lukezhu1
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(int a) {
	for (int i = 3; i <= sqrt(a); ++i) {
		if (!(a % i)) {
			return false;
		}
	}
	return true;
}

int main() {
	ofstream fout("pprime.out");
	ifstream fin("pprime.in");

	int a, b;
	fin >> a >> b;


	for (int i = 5; i <= 11; i +=2) {
		if (is_prime(i) && i >= a && i <= b) {
			fout << i << "\n";
		}
	}

	for (int d1 = 1; d1 <= 9; d1 += 2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			int pal;
			pal = 100 * d1 + 10 * d2 + d1;
			if (is_prime(pal) && pal >= a && pal <= b) {
				fout << pal << "\n";
			}
		}
	}
	for (int d1 = 1; d1 <= 9; d1 += 2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				int pal;
				pal = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
				if (is_prime(pal) && pal >= a && pal <= b) {
					fout << pal << "\n";
				}
			}
		}
	}
	for (int d1 = 1; d1 <= 9; d1 += 2) {
		for (int d2 = 0; d2 <= 9; d2++) {
			for (int d3 = 0; d3 <= 9; d3++) {
				for (int d4 = 0; d4 <= 9; d4++) {
					int pal;
					pal = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
					if (is_prime(pal) && pal >= a && pal <= b) {
						fout << pal << "\n";
					}
				}
			}
		}
	}
}