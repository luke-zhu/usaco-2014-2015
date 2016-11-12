/*
ID: lukezhu1
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char grid[10][10]; // (x, y)
int fjohn[2], cows[2], fjohn_dir, cows_dir, num_moves; // (up, right, down, left) = (0, 1, 2, 3)
void fjohn_move(), cows_move();
bool memoize();
int fjohn_mem[1000][3], cows_mem[1000][3];

int main() {
	ofstream fout("ttwo.out");
	ifstream fin("ttwo.in");

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			fin >> grid[j][i];
			if (grid[j][i] == 'F') {
				fjohn[0] = j;
				fjohn[1] = i;
				fjohn_dir = 0;
			}
			else if (grid[j][i] == 'C') {
				cows[0] = j;
				cows[1] = i;
				cows_dir = 0;
			}
		}
	}
	/*
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << grid[j][i] << " ";
		}
		cout << "\n";
	}
	*/
	while (fjohn[0] != cows[0] || fjohn[1] != cows[1]) {
		//cout << fjohn[0] << " " << fjohn[1] << ", " << cows[0] << " " << cows[1] << "\n";
		++num_moves;
		fjohn_move();
		cows_move();
		if (memoize()) {
			fout << 0 << "\n";
			return 0;
		}
	}
	fout << num_moves << "\n";
}

bool memoize() {
	for (int i = 0; i < num_moves; ++i) {
		if (fjohn[0] == fjohn_mem[i][0] && fjohn[1] == fjohn_mem[i][1] && fjohn_dir == fjohn_mem[i][2]) {
			if (cows[0] == cows_mem[i][0] && cows[1] == cows_mem[i][1] && cows_dir == cows_mem[i][2]) {
				//cout << i << " " << num_moves << "\n";
				return 1;
			}
		}
	}
	fjohn_mem[num_moves][0] = fjohn[0];
	fjohn_mem[num_moves][1] = fjohn[1];
	fjohn_mem[num_moves][2] = fjohn_dir;
	cows_mem[num_moves][0] = cows[0];
	cows_mem[num_moves][1] = cows[1];
	cows_mem[num_moves][2] = cows_dir;
	return 0;
}

void fjohn_move() {
	if (fjohn_dir== 0) {
		if (grid[fjohn[0]][fjohn[1] - 1] == '*' || fjohn[1] == 0) {
			++fjohn_dir;
		}
		else {
			--fjohn[1];
		}
	}
	else if (fjohn_dir == 1) {
		if (grid[fjohn[0] + 1][fjohn[1]] == '*' || fjohn[0] == 9) {
			++fjohn_dir;
		}
		else {
			++fjohn[0];
		}
	}
	else if (fjohn_dir == 2) {
		if (grid[fjohn[0]][fjohn[1] + 1] == '*' || fjohn[1] == 9) {
			++fjohn_dir;
		}
		else {
			++fjohn[1];
		}
	}
	else if (fjohn_dir == 3) {
		if (grid[fjohn[0] - 1][fjohn[1]] == '*' || fjohn[0] == 0) {
			fjohn_dir -= 3;
		}
		else {
			--fjohn[0];
		}
	}
}

void cows_move() {
	if (cows_dir == 0) {
		if (grid[cows[0]][cows[1] - 1] == '*' || cows[1] == 0) {
			++cows_dir;
		}
		else {
			--cows[1];
		}
	}
	else if (cows_dir == 1) {
		if (grid[cows[0] + 1][cows[1]] == '*' || cows[0] == 9) {
			++cows_dir;
		}
		else {
			++cows[0];
		}
	}
	else if (cows_dir == 2) {
		if (grid[cows[0]][cows[1] + 1] == '*' || cows[1] == 9) {
			++cows_dir;
		}
		else {
			++cows[1];
		}
	}
	else if (cows_dir == 3) {
		if (grid[cows[0] - 1][cows[1]] == '*' || cows[0] == 0) {
			cows_dir -= 3;
		}
		else {
			--cows[0];
		}
	}
}