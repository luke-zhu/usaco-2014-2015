#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int l_matrix[501][501], c_matrix[501][501], l[501], c[501], visited[501], parent[501];

int main() {
	ofstream fout("mroute.out");
	ifstream fin("mroute.in");

	for (int i = 1; i <= 500; ++i) {
		for (int j = 1; j <= 500; ++j) {
			c_matrix[i][j] = 1000000000;
			if (i != j) {
				l_matrix[i][j] = 1000000000;
			}
		}
	}

	int n, m, x;
	fin >> n >> m >> x;
	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		fin >> l_matrix[a][b] >> c_matrix[a][b];
		l_matrix[b][a] = l_matrix[a][b];
		c_matrix[b][a] = c_matrix[a][b];
	}

	for (int i = 1; i <= n; ++i) {
		l[i] = 1000000000;
		c[i] = 1000000000;
	}
	l[1] = 0;
	
	int num;
	num = 0;
	while (num < n) {
		int closest, j;
		closest = 1000000000;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i] && closest > l[i] + x / c[i]) {
				closest = l[i] + x / c[i];
				j = i;
			}
		}
		++num;
		visited[j] = 1;
		//cout << j << "\n";
		for (int i = 1; i <= n; ++i) {
			if (l[i] + x / c[i] > l[j] + l_matrix[i][j] + x / min(c[j], c_matrix[i][j])) {
				l[i] = l[j] + l_matrix[i][j];
				c[i] = min(c[j], c_matrix[i][j]);
				parent[i] = j;
			}
		}
	}
	fout << l[n] + x / c[n] << "\n";
}