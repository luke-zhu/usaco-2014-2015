#include <iostream>
#include <fstream>

using namespace std;

int n, m, q, r_shuffle[100001], query[5001];

int reverse(int index, int cards_left) {
	//cout << index << "\n";
	if (cards_left == n) {
		return index;
	}
	++cards_left;
	++index;
	if (cards_left < m) {
		return reverse(index + m - cards_left - 1, m - 1);
	}
	if (index > m) {
		return index + n - cards_left;
	}
	return reverse(r_shuffle[index], cards_left);
}

int main() {
	ofstream fout("shuffle.out");
	ifstream fin("shuffle.in");

	fin >> n >> m >> q;
	for (int i = 1; i <= m; ++i) {
		int index;
		fin >> index;
		r_shuffle[index] = i;
	}
	for (int i = 1; i <= q; ++i) {
		fin >> query[i];
		fout << reverse(0, query[i] - 1) << "\n";
	}
}