#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("painting.out");
	ifstream fin("painting.in");

	int n;
	fin >> n;
	struct Rectangle {
		int x1, y1, x2, y2;
	} enclosure[50000];

	bool compare(Rectangle a, Rectangle b) {
		if (a.x1 == b.x1) {
			return a.y1 < b.y1;
		}
		a.x1 < b.x1;
	}
	for (int i = 0; i < n; ++i) {
		fin >> enclosure[i].x1 >> enclosure[i].y1 >> enclosure[i].x2 >> enclosure[i].y2;
	}
	sort(enclosure, enclosure + n, compare);

	int min_y, max_x, max_y, outside;
	for (int i = 0; i < n; ++i) {

	}
}