#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
};

inline bool operator< (const Point& a, const Point& b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main() {
	ofstream fout("perimeter.out");
	ifstream fin("perimeter.in");

	int n; // 1..50,000
	fin >> n;
	Point bale[50000]; // 1..1,000,000
	for (int i = 0; i < n; ++i) {
		fin >> bale[i].x >> bale[i].y;
	}

	int perimeter;
	perimeter = 0;
	for (int i = 0; i < n; ++i) {

	}
}