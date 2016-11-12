/*
ID: lukezhu1
PROG: agrinet
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int matrix[100][100], dist[100], source[100];
bool intree[100];

int main() {
	ofstream fout("agrinet.out");
	ifstream fin("agrinet.in");

	int n;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		dist[i] = 100001;
	}

	int treesize, treecost;
	treesize = 1;
	treecost = 0;
	intree[0] = true;
	for (int i = 0; i < n; ++i) {
		dist[i] = matrix[0][i];
	}

	int source_node;
	source_node = 0;
	while (treesize < n) {
		int min_distance, neighbor;
		min_distance = 100001;
		for (int i = 0; i < n; ++i) {
			if (dist[i] < min_distance && !intree[i]) {
				min_distance = dist[i];
				neighbor = i;
			}
		}
		//cout << neighbor << "\n";
		source_node = neighbor;
		++treesize;
		treecost += dist[source_node];
		intree[source_node] = true;
		for (int i = 0; i < n; ++i) {
			if (matrix[source_node][i] < dist[i]) {
				dist[i] = matrix[source_node][i];
				source[i] = source_node;
			}
		}
	}
	cout << treecost << "\n";
	fout << treecost << "\n";
}