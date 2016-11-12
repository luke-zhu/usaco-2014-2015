#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int n, m, k, river[1000][2], b[1000];
char sequence[500];

int main() {
	ofstream fout("cruise.out");
	ifstream fin("cruise.in");

	fin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		fin >> river[i][0] >> river[i][1];
	}
	for (int i = 0; i < m; ++i) {
		fin >> sequence[i];
	}

	int curr;
	curr = 0;
	int rep_start, rep_len;
	rep_start = 0;
	rep_len = n;
	for (int i = 0; i < n; ++i) {
		b[i] = curr;
		bool rep;
		rep = false;
		for (int j = 0; j < i; ++j) {
			if (b[i] == b[j]) {
				rep_start = j;
				rep_len = i - j;
				rep = true;
				break;
			}
		}
		if (rep) {
			break;
		}
		for (int j = 0; j < m; ++j) {
			//cout << curr << " ";
			if (sequence[j] == 'L') {
				curr = river[curr][0] - 1;
			}
			else {
				curr = river[curr][1] - 1;
			}
		}
	}
	k = rep_start + (k - rep_start) % rep_len;
	fout << b[k] + 1 << "\n";
}