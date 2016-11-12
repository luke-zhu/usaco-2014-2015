#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Rectangle {
	int x1, y1, x2, y2;
};

bool operator< (const Rectangle& a, const Rectangle& b) {
	return a.x1 >= b.x1;
}

int main() {
	ofstream fout("planting.out");
	ifstream fin("planting.in");

	int n;
	fin >> n;
	Rectangle r[10];
	
}