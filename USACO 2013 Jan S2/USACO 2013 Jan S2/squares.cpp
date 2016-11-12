#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

pair <int, int> coord[50000];

int main() {
	ofstream fout("squares.out");
	ifstream fin("squares.in");

	int n, k;
	fin >> n >> k;
	for (int i = 0; i < n; ++i) {
		fin >> coord[i].first >> coord[i].second;
	}
	sort(coord, coord + n);

	int a, b, overlap;
	a = 0;
	b = 1;
	overlap = 0;
	bool overlapped;
	overlapped = false;
	while (a < n - 1) {
		//cout << a << " " << b << "\n";
		if (a == b) {
			++b;
			continue;
		}
		else if (coord[b].first - coord[a].first >= k) {
			++a;
			continue;
		}
		else if (coord[b].first - coord[a].first < k) {
			if (abs(coord[b].second - coord[a].second) < k) {
				//cout << coord[a].first << " " << coord[a].second << " " << coord[b].first << " " << coord[b].second << "\n";
				overlap = (k - coord[b].first + coord[a].first) * (k - abs(coord[b].second - coord[a].second));
				if (overlapped) {
					cout << -1 << "\n";
					return -1;
				}
				overlapped = true;
			}
		}
		++b;
	}
	cout << overlap << "\n";
}