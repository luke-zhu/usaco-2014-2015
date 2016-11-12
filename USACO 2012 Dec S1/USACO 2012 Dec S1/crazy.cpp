#include <iostream>
#include <fstream>

using namespace std;

int fence[1000][4], group[1000], cow[1000][2];

int main() {
	ofstream fout("crazy.out");
	ifstream fin("crazy.in");

	int n, c;
	fin >> n >> c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			fin >> fence[i][j];
		}
	}
	for (int i = 0; i < c; ++i) {
		fin >> cow[i][0] >> cow[i][1];
	}
	
	int num_groups;
	num_groups = 0;
	for (int i = 0; i < n; ++i) {
		if (group[i] == 0) {
			++num_groups;
			while (group[i] == 0) {
				group[i] = num_groups;
				for (int j = 0; j < n; ++j) {
					if (fence[i][0] == fence[j][0] && fence[i][1] == fence[j][1]) {
						i = j;
						break;
					}
					if (fence[i][2] == fence[j][0] && fence[i][3] == fence[j][1]) {
						i = j;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << group[i] << "\n";
	}
}