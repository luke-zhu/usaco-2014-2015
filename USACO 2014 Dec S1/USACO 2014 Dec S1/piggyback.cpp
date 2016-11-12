#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int b, e, p, n, m, dist[3][40001], min_energy;
set<int> path[40001];

void dijkstra(int from) {
	for (int i = 1; i <= n; ++i) {
		dist[from][i] = 1000000;
	}
	priority_queue<ii, vector<ii>, greater<ii>> q;
	if (from == 0) {
		dist[from][1] = 0;
		q.push(ii(0, 1));
	}
	else if (from == 1) {
		dist[from][2] = 0;
		q.push(ii(0, 2));
	}
	else {
		dist[from][n] = 0;
		q.push(ii(0, n));
	}
	while (!q.empty()) {
		int v = q.top().second;
		int d = q.top().first;
		q.pop();
		if (d == dist[from][v]) {
			for (set<int>::iterator it = path[v].begin(); it != path[v].end(); ++it) {
				if (dist[from][*it] > dist[from][v] + 1) {
					dist[from][*it] = dist[from][v] + 1;
					q.push(ii(dist[from][*it], *it));
				}
			}
		}
	}
}

int main() {
	ofstream fout("piggyback.out");
	ifstream fin("piggyback.in");

	fin >> b >> e >> p >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		path[a].insert(b);
		path[b].insert(a);
	}

	for (int i = 0; i < 3; ++i) {
		dijkstra(i);
	}

	min_energy = 1000000000;
	for (int i = 1; i <= n; ++i) {
		min_energy = min(min_energy, b * dist[0][i] + e * dist[1][i] + p * dist[2][i]);
	}
	fout << min_energy << "\n";
}