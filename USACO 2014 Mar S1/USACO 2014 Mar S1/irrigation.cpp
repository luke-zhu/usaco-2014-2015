#include <iostream>
#include <fstream>

#define INF 1000000000;

using namespace std;

int field[2000][2], dist[2000];
bool in_tree[2000];

int main() {
	ofstream fout("irrigation.out");
	ifstream fin("irrigation.in");

	int n, c;
	fin >> n >> c;
	for (int i = 0; i < n; ++i) {
		fin >> field[i][0] >> field[i][1];
	}

	int size, cost;
	size = 1;
	cost = 0;
	in_tree[0] = true;
	for (int i = 0; i < n; ++i) {
		dist[i] = (field[i][0] - field[0][0]) * (field[i][0] - field[0][0]);
		dist[i] += (field[i][1] - field[0][1]) * (field[i][1] - field[0][1]);
		if (dist[i] < c) {
			dist[i] = INF;
		}
	}
	while (size < n) {
		int min_dist, neighbor;
		min_dist = INF;
		for (int i = 0; i < n; ++i) {
			if (!in_tree[i] && dist[i] < min_dist) {
				min_dist = dist[i];
				neighbor = i;
			}
		}
		if (min_dist == 1000000000) {
			fout << -1 << "\n";
			return 0;
		}
		++size;
		cost += min_dist;
		in_tree[neighbor] = true;
		for (int i = 0; i < n; ++i) {
			int new_dist;
			new_dist = (field[i][0] - field[neighbor][0]) * (field[i][0] - field[neighbor][0]);
			new_dist += (field[i][1] - field[neighbor][1]) * (field[i][1] - field[neighbor][1]);
			if (dist[i] > new_dist && new_dist >= c) {
				dist[i] = new_dist;
			}
		}
	}
	fout << cost << "\n";
}