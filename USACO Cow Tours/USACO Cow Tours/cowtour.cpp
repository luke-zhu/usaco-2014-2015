/*
ID: lukezhu1
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
int n, group[150];
double grid[150][2], diameters[150];
string matrix[150];
double weighted[150][150], dist[150][150]; //(x, y)

int main() {
	ofstream fout("cowtour.out");
	ifstream fin("cowtour.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> grid[i][0] >> grid[i][1];
	}
	for (int i = 0; i < n; ++i) {
		fin >> matrix[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == '1') {
				weighted[i][j] = sqrt((grid[j][0] - grid[i][0]) * (grid[j][0] - grid[i][0]) + (grid[j][1] - grid[i][1]) * (grid[j][1] - grid[i][1]));
			}
			else if (i == j) {
				weighted[i][j] = 0;
			}
			else {
				weighted[i][j] = 1000000000;
			}
		}
	}
	//cout << "clear: input" << "\n";
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
				dist[i][j] = weighted[i][j];
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	//cout << "clear: A" << "\n";
	int group_num;
	group_num = 1;
	group[0] = group_num;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (dist[i][j] != 1000000000) {
				group[i] = group[j];
				continue;
			}
		}
		if (group[i] == 0) {
			++group_num;
			group[i] = group_num;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (group[i] == group[j] && dist[i][j] > diameters[group[i]]) {
				diameters[group[i]] = dist[i][j];
			}
		}
	}

	double min_diameter;
	min_diameter = 1000000000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dist[i][j] != 1000000000) {
				continue;
			}
			double max_i, max_j;
			max_i = 0;
			max_j = 0;
			for (int k = 0; k < n; ++k) {
				if (dist[i][k] != 1000000000 && dist[i][k] > max_i) {
					max_i = dist[i][k];
				}
				if (dist[j][k] != 1000000000 && dist[j][k] > max_j) {
					max_j = dist[j][k];
				}
			}
			double diameter;
			diameter = sqrt((grid[j][0] - grid[i][0]) * (grid[j][0] - grid[i][0]) + (grid[j][1] - grid[i][1]) * (grid[j][1] - grid[i][1]));
			diameter += max_i;
			diameter += max_j;
			//cout << diameter << "\n";
			diameter = max(max(diameter, diameters[group[i]]), diameters[group[j]]);
			if (diameter < min_diameter) {
				min_diameter = diameter;
			}
		}
	}
	cout << setprecision(6) << fixed << min_diameter << "\n";
	fout << setprecision(6) << fixed << min_diameter << "\n";
}