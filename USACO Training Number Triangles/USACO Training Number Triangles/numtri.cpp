/*
ID: lukezhu1
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int r, nums[1001][1001];

int main() {
	ofstream fout("numtri.out");
	ifstream fin("numtri.in");

	fin >> r;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= i; ++j) {
			fin >> nums[i][j];
		}
	}
	

	int max_sum;
	max_sum = 0;
	for (int i = 2; i <= r; ++i) {
		for (int j = 1; j <= r; ++j) {
			if (j == 1) {
				nums[i][1] += nums[i - 1][1];
			}
			else if (j == i) {
				nums[i][j] += nums[i - 1][j - 1];
			}
			else {
				nums[i][j] += max(nums[i - 1][j], nums[i - 1][j - 1]);
			}
		}
	}
	
	int max_num;
	max_num = 0;
	for (int i = 1; i <= r; ++i) {
		max_num = max(max_num, nums[r][i]);
	}

	fout << max_num << "\n";
}