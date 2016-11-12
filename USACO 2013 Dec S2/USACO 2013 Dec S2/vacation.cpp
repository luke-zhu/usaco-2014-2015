#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int matrix[201][201], dist[201][201];

int main() {
	ofstream fout("vacation.out");
	ifstream fin("vacation.in");

	int n, m, k, q;
	fin >> n >> m >> k >> q;
	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		fin >> matrix[a][b];
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (matrix[i][j]) {
				dist[i][j] = matrix[i][j];
			}
			else if (i != j) {
				dist[i][j] = 1000000000;
			}
		}
	}

	for (int x = 1; x <= n; ++x) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][x] + dist[x][j] < dist[i][j]) {
					dist[i][j] = dist[i][x] + dist[x][j];
				}
			}
		}
	}
	int possible;
	long long sum;
	possible = 0;
	sum = 0;
	for (int i = 0; i < q; ++i) {
		int a, b;
		fin >> a >> b;
		int shortest;
		shortest = 1000000000;
		for (int j = 1; j <= k; ++j) {
			shortest = min(shortest, dist[a][j] + dist[j][b]);
		}
		if (shortest != 1000000000) {
			++possible;
			sum += shortest;
		}
	}
	fout << possible << "\n";
	fout << sum << "\n";
}