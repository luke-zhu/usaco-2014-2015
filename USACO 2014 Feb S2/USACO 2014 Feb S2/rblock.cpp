#include <iostream>
#include <fstream>
#include <algorithm>

#define INF 1000000000;

using namespace std;

int n, matrix[251][251];

int dijkstra() {
	int dist[251], visited[251];
	for (int i = 2; i <= n; ++i) {
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[1] = 0;
	visited[1] = 0;
	int nodes_visited;
	nodes_visited = 0;
	while (nodes_visited < n) {
		int closest_dist, closest_node;
		closest_dist = INF;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i] && dist[i] < closest_dist) {
				closest_dist = dist[i];
				closest_node = i;
			}
		}
		visited[closest_node] = 1;
		++nodes_visited;
		for (int i = 1; i <= n; ++i) {
			if (dist[closest_node] + matrix[i][closest_node] < dist[i]) {
				dist[i] = dist[closest_node] + matrix[i][closest_node];
			}
		}
	}
	return dist[n];
}

int main() {
	for (int i = 1; i <= 250; ++i) {
		for (int j = 1; j <= 250; ++j) {
			if (i != j) {
				matrix[i][j] = INF;
			}
		}
	}

	ofstream fout("rblock.out");
	ifstream fin("rblock.in");

	int m;
	fin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		fin >> matrix[a][b];
		matrix[b][a] = matrix[a][b];
	}
	
	int orig_dist;
	orig_dist = dijkstra();
	//cout << orig_dist << "\n";
	int max_dist;
	max_dist = orig_dist;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (matrix[i][j] <= 1000000) {
				matrix[i][j] *= 2;
				matrix[j][i] *= 2;
				max_dist = max(max_dist, dijkstra());
				matrix[i][j] /= 2;
				matrix[j][i] /= 2;
			}
		}
	}
	fout << max_dist - orig_dist << "\n";
}