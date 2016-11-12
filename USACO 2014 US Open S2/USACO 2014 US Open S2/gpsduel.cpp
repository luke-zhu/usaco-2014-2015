#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int matrix[10001][10001][2], dist[10001][2], visited[10001][2], source[10001][2];

int main() {
	ofstream fout("gpsduel.out");
	ifstream fin("gpsduel.in");

	int n, m;
	fin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				matrix[i][j][0] = 1000000;
				matrix[i][j][1] = 1000000;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b, p, q;
		fin >> a >> b >> p >> q;
		matrix[a][b][0] = min(matrix[a][b][0], p);
		matrix[a][b][1] = min(matrix[a][b][1], q);
	}

	for (int i = 1; i < n; ++i) {
		dist[i][0] = 1000000;
		dist[i][1] = 1000000;
	}
	int size;
	size = 0;
	while (size < n) {
		int closest_d[2], closest_n[2];
		closest_d[0] = 1000000;
		closest_d[1] = 1000000;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i][0] && dist[i][0] < closest_d[0]) {
				closest_d[0] = dist[i][0];
				closest_n[0] = i;
			}
			if (!visited[i][1] && dist[i][1] < closest_d[1]) {
				closest_d[1] = dist[i][1];
				closest_n[1] = i;
			}
		}
		++size;
		visited[closest_n[1]][1] = 1;
		visited[closest_n[0]][0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (dist[i][0] > matrix[i][closest_n[0]][0] && i != closest_n[0]) {
				dist[i][0] = matrix[i][closest_n[0]][0];
				source[i][0] = closest_n[0];
			}
			if (dist[i][1] > matrix[i][closest_n[1]][1] && i != closest_n[1]) {
				dist[i][1] = matrix[i][closest_n[1]][1];
				source[i][1] = closest_n[1];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) {
				continue;
			}
			if (matrix[i][j][0] == 1000000) {
				continue;	
			}
			matrix[i][j][0] = 0;
			if (source[i][0] != j) {
				++matrix[i][j][0];
			}
			if (source[i][1] != j) {
				++matrix[i][j][0];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		dist[i][0] = matrix[1][i][0];
		visited[i][0] = 0;
	}
	visited[1][0] = 1;
	size = 1;
	while (size < n) {
		int closest_d, closest_n;
		closest_d = 1000000;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i][0] && closest_d > dist[i][0]) {
				closest_d = dist[i][0];
				closest_n = i;
			}
			//cout << closest_d << " " << closest_n << "\n";
		}
		++size;
		visited[closest_n][0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (dist[i][0] > dist[closest_n][0] + matrix[closest_n][i][0]) {
				dist[i][0] = dist[closest_n][0] + matrix[closest_n][i][0];
			}
		}
	}
	fout << dist[n][0] << "\n";
	cout << dist[n][0] << "\n";
}