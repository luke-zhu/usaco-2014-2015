#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r, l , t, b;
array < array < char, 1002 >, 1002 > rectangle;
vector < pair < int, int > > right, left, top, bot;

int from_right(int x, int y, int len) {
	if (x == 0 || x == n + 1 || y == 0 || y == n + 1) {
		return len;
	}
	if (rectangle[x][y] == '/') {
		return from_top(x, y - 1, len + 1);
	}
	else {
		return from_bot(x, y + 1, len + 1);
	}
}

int from_left(int x, int y, int len) {
	if (x == 0 || x == n + 1 || y == 0 || y == n + 1) {
		return len;
	}
	if (rectangle[x][y] == '/') {
		return from_bot(x, y + 1, len + 1);
	}
	else {
		return from_top(x, y - 1, len + 1);
	}
}

int from_top(int x, int y, int len) {
	if (x == 0 || x == n + 1 || y == 0 || y == n + 1) {
		return len;
	}
	if (rectangle[x][y] == '/') {
		return from_right(x - 1, y, len + 1);
	}
	else {
		return from_left(x + 1, y, len + 1);
	}
}

int from_bot(int x, int y, int len) {
	if (x == 0 || x == n + 1 || y == 0 || y == n + 1) {
		return len;
	}
	else if (find)
	if (rectangle[x][y] == '/') {
		return from_left(x + 1, y, len + 1);
	}
	else {
		return from_right(x - 1, y, len + 1);
	}
}

int main() {
	ofstream fout("mirror.out");
	ifstream fin("mirror.in");

	fin >> n >> m;
	r = 0; l = 0; t = 0; b = 0;
	for (int i = 1; i <- n; ++i) {
		for (int j = 1; j <= m; ++j) {
			fin >> rectangle[i][j];
		}
	}
}