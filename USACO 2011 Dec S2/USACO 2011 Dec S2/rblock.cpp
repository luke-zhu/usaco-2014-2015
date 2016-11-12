#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, pathway[100][100], orig, max_inc;

int dijkstra() {
	int dist[100];
	dist[0] = 0;
	for (int i = 1; i < n; ++i) {
		dist[i] = 1000000000;
	}
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pq.push(pair<int, int>(0, 0));
	while(!pq.empty()) {
		pair<int, int> top;
		top = pq.top();
		pq.pop();
		int v, d;
		v = top.second;
		d = top.first;
		if (d == dist[v]) {
			for (int i = 0; i < n; ++i) {
				if (dist[i] > pathway[v][i] + dist[v]) {
					dist[i] = pathway[v][i] + dist[v];
					pq.push(pair<int, int>(dist[i], i));
				}
			}
		}
	}
	return dist[n - 1];
}

int main() {
	ofstream fout("rblock.out");
	ifstream fin("rblock.in");
	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				pathway[i][j] = 1000000000;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		fin >> pathway[--a][--b];
		pathway[b][a] = pathway[a][b];
	}
	
	orig = dijkstra();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (pathway[i][j] != 1000000000) {
				pathway[i][j] *= 2;
				pathway[j][i] *= 2;
				max_inc = max(max_inc, dijkstra() - orig);
				pathway[i][j] /= 2;
				pathway[j][i] /= 2;
			}
		}
	}
	cout << max_inc << "\n";
}