#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, g, b, d, filled[50000];

struct Station {
	int x, y;
} station[50000];

bool inline operator< (const Station& a, const Station& b) {
	if (a.x == a.y) {
		return b.x < b.y;
	}
	return a.x < a.y;
}

int main() {
	ofstream fout("fuel.out");
	ifstream fin("fuel.in");

	fin >> n >> g >> b >> d;
	if (b > g) {
		b = g;
	}
	for (int i = 0; i < n; ++i) {
		fin >> station[i].x>> station[i].y;
	}
	sort(station, station + n);

	
}