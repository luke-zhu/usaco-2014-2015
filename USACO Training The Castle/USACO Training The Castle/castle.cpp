/*
ID: lukezhu1
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m;
int wall[51][51][4];
int room[51][51], size[2501];


void flood_fill(int x, int y, int color) {
	if (room[x][y]) {
		return;
	}
	++size[color];
	room[x][y] = color;
	if (!wall[x][y][0]) {
		flood_fill(x - 1, y, color);
	}
	if (!wall[x][y][3]) {
		flood_fill(x, y + 1, color);
	}
	if (!wall[x][y][1]) {
		flood_fill(x, y - 1, color);
		
	}
	if (!wall[x][y][2]) {
		flood_fill(x + 1, y, color);
	}
}

int main() {
	ofstream fout("castle.out");
	ifstream fin("castle.in");

	fin >> m >> n;
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= m; ++i) {
			int x;
			fin >> x;
			if (x >= 8) {
				wall[i][j][3] = 1;
				x -= 8;
			}
			if (x >= 4) {
				wall[i][j][2] = 1;
				x -= 4;
			}
			if (x >= 2) {
				wall[i][j][1] = 1;
				x -= 2;
			}
			if (x >= 1) {
				wall[i][j][0] = 1;
			}
		}
	}

	int color;
	color = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			flood_fill(i, j, color);
			if (size[color]) {
				//cout << i << " " << j << "\n";
				++color;
			}
		}
	}
	fout << color - 1 << "\n";

	int max_size;
	max_size = 0;
	for (int i = 1; i <= color; ++i) {
		max_size = max(max_size, size[i]);
	}
	fout << max_size << "\n";

	pair < int, pair < pair < int, int >, char > > max_room;
	max_room.first = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = n; j > 0; --j) {
			int r_size;
			r_size = 0;
			if (room[i][j] != room[i][j - 1]) {
				r_size = size[room[i][j]] + size[room[i][j - 1]];
				//cout << r_size << " " << i << " " << j << "\n";
			}
			if (r_size > max_room.first) {
				max_room.first = r_size;
				max_room.second.first.first = i;
				max_room.second.first.second = j;
				max_room.second.second = 'N';
			}
			if (room[i][j] != room[i + 1][j]) {
				r_size = size[room[i][j]] + size[room[i + 1][j]];
				//cout << r_size << " " << i << " " << j << "\n";
			}
			if (r_size > max_room.first) {
				max_room.first = r_size;
				max_room.second.first.first = i;
				max_room.second.first.second = j;
				max_room.second.second = 'E';
			}
		}
	}
	fout << max_room.first << "\n";
	fout << max_room.second.first.second << " " <<max_room.second.first.first << " " << max_room.second.second << "\n";
}