#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("slowdown.out");
	ifstream fin("slowdown.in");

	int n;
	fin >> n;
	int t[10000], d[10000], num_t, num_d;
	num_t = 0;
	num_d = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		fin >> c;
		if (c == 'T') {
			fin >> t[num_t];
			++num_t;
		}
		else {
			fin >> d[num_d];
			++num_d;
		}
	}
	sort(t, t + num_t);
	sort(d, d + num_d);

	int inv_s;
	inv_s = 1;
	int a, b;
	a = 0;
	b = 0;
	double curr_t, curr_d;
	curr_t = 0;
	curr_d = 0;
	while (a < num_t && b < num_d) {
		if (t[a] - curr_t < (d[b] - curr_d) * inv_s) {
			curr_d += (t[a] - curr_t) / inv_s;
			curr_t = t[a];
			++a;
		}
		else {
			curr_t += (d[b] - curr_d) * inv_s;
			curr_d = d[b];
			++b;
		}
		++inv_s;
	}
	while (a < num_t) {
		curr_d += (t[a] - curr_t) / inv_s;
		curr_t = t[a];
		++a;
		++inv_s;
	}
	while (b < num_d) {
		curr_t += (d[b] - curr_d) * inv_s;
		curr_d = d[b];
		++b;
		++inv_s;
	}
	curr_t += (1000 - curr_d) * inv_s;
	curr_d = 1000;
	int int_answer;
	if (curr_t - (int)curr_t > .5) {
		int_answer = (int)curr_t + 1;
	}
	else {
		int_answer = (int)curr_t;
	}
	fout << int_answer << "\n";
}