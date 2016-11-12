#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int k;

int floodfill(int curr_a, int curr_b, int len, vector < vector < int > > curr_grid) {
	if (curr_a < 0 || curr_a > 4 || curr_b < 0 || curr_b > 4) {
		//cout << curr_a << " " << curr_b << "\n";
		//cout << "end\n";
		return 0;
	}
	else if (curr_grid[curr_a][curr_b]) {
		//cout << curr_a << " " << curr_b << "\n";
		//cout << "end\n";
		return 0;
	}
	else if (len == 25 - k && curr_a == 4 && curr_b == 4) {
		//cout << curr_a << " " << curr_b << "\n";
		//cout << "end\n";
		return 1;
	}
	vector < vector < int > > new_grid;
	new_grid = curr_grid;
	new_grid[curr_a][curr_b] = 1;
	++len;
	return floodfill(curr_a - 1, curr_b, len, new_grid) + floodfill(curr_a, curr_b - 1, len, new_grid) + floodfill(curr_a + 1, curr_b, len, new_grid) + floodfill(curr_a, curr_b + 1, len, new_grid);
}

int main() {
	ofstream fout("grazing.out");
	ifstream fin("grazing.in");

	fin >> k; 
	vector < vector < int > > orig_grid(5, vector<int>(5, 0));
	for (int i = 0; i < k; ++i) {
		int a, b;
		fin >> a >> b;
		orig_grid[a - 1][b - 1] = 1;
	}
	/*
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << orig_grid[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	cout << floodfill(0, 0, 1, orig_grid) << "\n";
}