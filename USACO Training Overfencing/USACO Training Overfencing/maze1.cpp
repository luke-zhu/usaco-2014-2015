/*
ID: lukezhu1
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int w, h;
string grid[201];
int fenced[100][100][4], dist[100][100]; // (west, north, east, south)
queue<int> i_queue, j_queue, d_queue;

void find_distance(int, int, int);

void bfs() {
	int i, j, d;
	while (!i_queue.empty()) {
		i = i_queue.front();
		j = j_queue.front();
		d = d_queue.front();
		i_queue.pop();
		j_queue.pop();
		d_queue.pop();
		find_distance(i, j, d);
	}
}

void find_distance(int i, int j, int d) {
	//cout << i << " " << j << " " << d << "\n";
	if (d >= dist[i][j]) {
		return;
	}
	dist[i][j] = d;
	if (!fenced[i][j][0] && j != 0) {
		i_queue.push(i);
		j_queue.push(j - 1);
		d_queue.push(d + 1);
	}
	if (!fenced[i][j][1] && i != 0) {
		i_queue.push(i - 1);
		j_queue.push(j);
		d_queue.push(d + 1);
	}
	if (!fenced[i][j][2] && j != w - 1) {
		i_queue.push(i);
		j_queue.push(j + 1);
		d_queue.push(d + 1);
	}
	if (!fenced[i][j][3] && i != h - 1) {
		i_queue.push(i + 1);
		j_queue.push(j);
		d_queue.push(d + 1);
	}
	bfs();
}

int main() {
	ofstream fout("maze1.out");
	ifstream fin("maze1.in");

	fin >> w >> h;
	string s;
	getline(fin, s);
	for (int i = 0; i < 2 * h + 1; ++i) {
		getline(fin, grid[i]);
	}
	/*
	for (int i = 0; i < 2 * h + 1; ++i) {
		cout << grid[i] << "\n";
	}
	*/
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (grid[2 * i + 1][2 * j] == '|') {
				fenced[i][j][0] = 1;
			}
			if (grid[2 * i][2 * j + 1] == '-') {
				fenced[i][j][1] = 1;
			}
			if (grid[2 * i + 1][2 * j + 2] == '|') {
				fenced[i][j][2] = 1;
			}
			if (grid[2 * i + 2][2 * j + 1] == '-') {
				fenced[i][j][3] = 1;
			}
		}
	}
	/*
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cout << fenced[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	*/
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			dist[i][j] = 10000;
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (i == 0 && !fenced[i][j][1]) {
				find_distance(i, j, 1);
			}
			else if (j == 0 && !fenced[i][j][0]) {
				find_distance(i, j, 1);
			}
			else if (i == h - 1 && !fenced[i][j][3]) {
				find_distance(i, j, 1);
			}
			else if (j == w - 1 && !fenced[i][j][2]) {
				find_distance(i, j, 1);
			}
		}
	}
	
	int max_dist;
	max_dist = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << dist[i][j] << " ";
			if (dist[i][j] > max_dist) {
				max_dist = dist[i][j];
			}
		}
		cout << "\n";
	}
	fout << max_dist << "\n";
}