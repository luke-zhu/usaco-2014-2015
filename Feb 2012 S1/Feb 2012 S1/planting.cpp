#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Rect {
	int x1, y1, x2, y2;
};

bool operator<(const Rect& a, const Rect& b) {
	return a.y1 > b.y1;
}

int main() {
	ofstream fout("planting.out");
	ifstream fin("planting.in");

	int n;
	fin >> n;
	Rect cords[1000];
	int x_cords[2000];
	for (int i = 0; i < n; ++i) {
		fin >> cords[i].x1 >> cords[i].y1 >> cords[i].x2 >> cords[i].y2;
		x_cords[2 * i] = cords[i].x1;
		x_cords[2 * i + 1] = cords[i].x2;
	}
	sort(cords, cords + n);
	sort(x_cords, x_cords + 2 * n);
	/*
	for (int i = 0; i < n; ++i) {
		cout << cords[i].x1 << " " << cords[i].y1 << "\n";
	}
	*/
	long long area;
	area = 0;
	for (int i = 0; i < 2 * n - 1; ++i) {
		int y_sum = 0, y_lower = 1000000000;
		for (int j = 0; j < n; ++j) {
			if (cords[j].x1 <= x_cords[i] && cords[j].x2 > x_cords[i]) {
				if (cords[j].y1 < y_lower) {
					y_sum += cords[j].y1 - cords[j].y2;
					y_lower = cords[j].y2;
				}
				else if (cords[j].y2 < y_lower) {
					y_sum += y_lower - cords[j].y2;
					y_lower = cords[j].y2;
				}
			}
		}
		//cout << y_sum << " " << x_cords[i + 1] << " " << x_cords[i] << "\n";
		area += y_sum * (x_cords[i + 1] - x_cords[i]);
	}

	cout << area << "\n";
}