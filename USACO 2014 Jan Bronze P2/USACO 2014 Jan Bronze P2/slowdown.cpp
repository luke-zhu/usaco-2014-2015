#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int main() {
	ofstream fout("slowdown.out");
	ifstream fin("slowdown.in");

	int n;
	array < int, 10000 > times, distances;

	fin >> n;
	int a, b;
	a = 0;
	b = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		fin >> c;
		if (c == 'T') {
			fin >> times[a];
			++a;
		}
		else {
			fin >> distances[b];
			++b;
		}
	}
	fin.close();

	int t_ind, d_ind;
	double t_traveled, d_traveled;
	t_traveled = 0;
	d_traveled = 0;
	t_ind = 0;
	d_ind = 0;
	double inv_s;
	inv_s = 1;
	while (d_traveled <= 1000) {
		// No more slowdown
		if (t_ind == a && d_ind == b) {
			t_traveled = inv_s * (1000 - d_traveled);
			break;
		}
		// No more D slowdown
		else if (d_ind == b) {
			d_traveled += 1 / inv_s * (times[t_ind] - t_traveled);
			t_traveled = times[t_ind];
			++t_ind;
		}
		// No more T slowdown or D slowdown closer
		else if (t_ind == a || distances[d_ind] - d_traveled < 1 / inv_s * (times[t_ind] - t_traveled)) {
			t_traveled += inv_s * (distances[d_ind] - d_traveled);
			d_traveled = distances[d_ind];
			++d_ind;
		}
		// T slowdown closer
		else {
			d_traveled += 1 / inv_s * (times[t_ind] - t_traveled);
			t_traveled = times[t_ind];
			++t_ind;
		}
		++inv_s;
	}
	fout << (int) t_traveled << "\n";
}