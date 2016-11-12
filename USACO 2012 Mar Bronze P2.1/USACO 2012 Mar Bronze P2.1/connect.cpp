#include <iostream>
#include <fstream>

using namespace std;

int n, cow[2001][2001], change_dir[2001][2001]; //0-999 1000 1001-2000

int recursive_sol(int h, int v, char dir, int changes) {
	int total
	if (dir == 'n') {
		for (int i = 0; i <= 2000 - v; ++i) {
			if (cow[h][v + i]) {

			}
		}
	}
	else if (dir == 's') {
		for (int i = 0; i < n; ++i) {

		}
	}
	else if (dir == 'e') {
		for (int i = 0; i < n; ++i) {

		}
	}
	else if (dir == 'w') {
		for (int i = 0; i < n; ++i) {

		}
	}
}

int main() {
	ofstream fout("connect.out");
	ifstream fin("connect.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		int h, v;
		cow[h + 1000][v + 1000] = 1;
	}
	cout << recursive_sol(1000, 1000, 'n', 0) + recursive_sol(1000, 1000, 's', 0) + recursive_sol(1000, 1000, 'e', 0) + recursive_sol(1000, 1000, 'w', 0) << "\n";
}