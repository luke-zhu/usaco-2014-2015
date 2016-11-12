#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m, p_road[10000][10000], q_road[10000][10000];

int main() {
	for (int i = 0; i < 10000; ++i) {
		for (int j = 0; j < 10000; ++j) {
			p_road[i][j] = 1000000000;
			q_road[i][j] = 1000000000;
		}
	}
	// Input
	ofstream fout("gpsduel.out");
	ifstream fin("gpsduel.in");
	fin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		int temp_i;
		fin >> temp_i;
		p_road[a][b] = min(p_road[a][b], temp_i);
		fin >> temp_i;
		q_road[a][b] = min(q_road[a][b], temp_i);
	}
	// Djikstra's
	in
}