#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int m, n;
string cows[50]; // [y][x]
int spotted[50][50]; // [y][x]


bool floodfill(int x, int y, int group) {
	//cout << x << " " << y << "\n";
	if (x == -1 || x == m || y ==-1 || y == n) {
		return false;
	}
	else if (cows[y][x] != 'X' || spotted[y][x]) {
		return false;
	}
	spotted[y][x] = group;
	floodfill(x - 1, y, group);
	floodfill(x + 1, y, group);
	floodfill(x, y - 1, group);
	floodfill(x, y + 1, group);
	return true;
}

int min_distance(int group1, int group2) {
	int minimum;
	minimum = 100;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = i; k < m; ++k) {
				for (int l = j; l < n; ++l) {
					if (spotted[j][i] == group1 && spotted[l][k] == group2) {
						minimum = min(minimum, k + l - i - j);
						//cout << minimum << "\n";
					}
					else if (spotted[j][i] == group2 && spotted[l][k] == group1) {
						minimum = min(minimum, k + l - i - j);
						//cout << minimum << "\n";
					}
				}
			}
		}
	}
	return minimum;
}

int main() {
	ofstream fout("pageant.out");
	ifstream fin("pageant.in");

	fin >> n >> m;
	for (int i = 0; i < n; ++i) {
		fin >> cows[i];
	}
	/*cout << n << " " << m << "\n";
	for (int i = 0; i < n; ++i) {
		cout << cows[i] << "\n";
	}
	cout << "\n";*/

	int group;
	group = 1;
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			if (cows[j][i] == 'X' && !spotted[j][i]) {
				floodfill(i, j, group);
				++group;
			}
		}
	}
	/*for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			cout << spotted[j][i];
		}
		cout << "\n";
	}
	cout << "\n";*/
	int a, b, c, minimum;
	a = min_distance(1, 2) - 1;
	b = min_distance(1, 3) - 1;
	c = min_distance(2, 3) - 1;
	minimum = min(a + b, a + c);
	minimum = min(minimum, b + c);
	cout << minimum << "\n";
}