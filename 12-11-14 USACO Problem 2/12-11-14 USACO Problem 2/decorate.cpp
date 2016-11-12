#include <iostream>
#include <fstream>

using namespace std;

int n, m, path[100000][2], letter[50000];

int main() {
	ofstream fout("decorate.out");
	ifstream fin("decorate.in");
	fin >> n >> m;
	for (int i = 0; i < m; ++i) {
		fin >> path[i][0] >> path[i][1];
	}

	for (int i = 0; i < n; ++i) {

	}
}