#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("proximity.out");
	ifstream fin("proximity.in");
	
	int n, k;
	fin >> n >> k;
	int line[50000];
	for (int i = 0; i < n; ++i) {
		fin >> line[i];
	}
	int max_id;
	max_id = -1;
	for (int i = 0; i < n - k; ++i) {
		bool crowded;
		crowded = false;
		for (int j = 1; j <= k; ++j) {
			if (line[i] == line[i + j]) {
				crowded = true;
				break;
			}
		}
		if (crowded) {
			max_id = max(max_id, line[i]);
		}
	}
	cout << max_id << "\n";
}