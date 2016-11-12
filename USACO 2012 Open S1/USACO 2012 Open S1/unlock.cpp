#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int n1, n2, n3;
bool coord1[10][10], coord2[10][10], coord3[10][10];

queue<vector<int>> q;

int bfs(vector<int> v, int moves) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (coord1[i])
		}
	}
}

int main() {
	ofstream fout("unlock.out");
	ifstream fin("unlock.in");

	fin >> n1 >> n2 >> n3;
	for (int i = 0; i < n1; ++i) {
		int a, b;
		fin >> a >> b;
		coord1[a][b] = 1;
	}
	for (int i = 0; i < n2; ++i) {
		int a, b;
		fin >> a >> b;
		coord2[a][b] = 1;
	}
	for (int i = 0; i < n3; ++i) {
		int a, b;
		fin >> a >> b;
		coord3[a][b] = 1;
	}
}