#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, ordering[20000];
map <int, int> pos[5];

int cmp(int a, int b) {
	int num_before = 0;
	for (int i = 0; i < 5; ++i) {
		if (pos[i][a] < pos[i][b]) {
			++num_before;
		}
	}
	num_before > 2;
}

int main() {
	ofstream fout("photo.out");
	ifstream fin("photo.in");

	fin >> n;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < n; ++j) {
			int id;
			fin >> id;
			pos[i][id] = j;
			ordering[j] = id;
		}
	}
	sort(ordering, ordering + n, cmp);
	for (int i = 0; i < n; ++i) {
		fout << ordering[i] << "\n";
	}
}