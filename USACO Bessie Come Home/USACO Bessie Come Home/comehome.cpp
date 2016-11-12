/*
ID: lukezhu1
PROG: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define inf 1000000000;
int dist[58][58];

int main() {
	ofstream fout("comehome.out");
	ifstream fin("comehome.in");

	//cout << (int)'Z' << "\n";
	for (int i = 0; i < 58; ++i) {
		for (int j = 0; j < 58; ++j) {
			if (i != j) {
				dist[i][j] = inf;
			}
		}
	}

	int p;
	fin >> p;
	for (int i = 0; i < p; ++i) {
		char pas_a, pas_b;
		fin >> pas_a >> pas_b;
		//cout << pas_a << " " << pas_b << "\n";
		int path;
		fin >> path;
		dist[(int)pas_a - 65][(int)pas_b - 65] = min(path, dist[(int)pas_a - 65][(int)pas_b - 65]);
		dist[(int)pas_b - 65][(int)pas_a - 65] = dist[(int)pas_a - 65][(int)pas_b - 65];
		//cout << (int)pas_a - 65 << " " << (int)pas_b - 65 << " " << dist[(int)pas_a - 65][(int)pas_b - 65] << "\n";
	}
	
	for (int k = 0; k < 58; ++k) {
		for (int i = 0; i < 58; ++i) {
			for (int j = 0; j < 58; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int shortest, pasture;
	shortest = inf;
	pasture = inf;
	for (int i = 0; i < 25; ++i) {
		//cout << char(i + 65) << " " << dist[i][25] << "\n";
		if (dist[i][25] < shortest) {
			shortest = dist[i][25];
			pasture = i;
		}
	}
	cout << (char)(pasture + 65) << " " << shortest << "\n";
	fout << (char)(pasture + 65) << " " << shortest << "\n";
}

