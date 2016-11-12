/*
ID: lukezhu1
PROG: fence
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int f, num_fences[501], fences[501][501];
int tour[1024], tour_pos;

void find_circuit(int i) {
	//cout << i << "\n";
	while (num_fences[i]) {
		for (int j = 1; j <= 500; ++j) {
			if (fences[i][j]) {
				--fences[i][j];
				--fences[j][i];
				--num_fences[i];
				--num_fences[j];
				find_circuit(j);
				break;
			}
		}
	}
	tour[tour_pos] = i;
	++tour_pos;
	//cout << "clear\n";
}

int main() {
	ifstream cin("fence.in");
	ofstream cout("fence.out");

	cin >> f;

	for (int i = 0; i < f; ++i) {
		int x, y;
		cin >> x >> y;
		++fences[x][y];
		++fences[y][x];
		++num_fences[x];
		++num_fences[y];
	}
	for (int i = 1; i <= 500; ++i) {
		if (num_fences[i] % 2) {
			find_circuit(i);
			for (int i = tour_pos - 1; i >= 0; --i) {
				cout << tour[i] << "\n";
			}
			break;
		}
	}
	if (!tour_pos) {
		find_circuit(1);
		for (int i = tour_pos - 1; i >= 0; --i) {
			cout << tour[i] << "\n";
		}
	}
}