/*
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int cow[100000][2], slowest[100000];

int main() {
	ofstream fout("cowjog.out");
	ifstream fin("cowjog.in");

	for (int i = 0; i < 100000; ++i) {
		slowest[i] = -1;
	}

	int n;
	fin >> n;
	int min_s, count;
	fin >> cow[0][0] >> cow[0][1];
	min_s = cow[0][1];
	slowest[0] = cow[0][0];
	count = 1;
	for (int i = 1; i < n; ++i) {
		fin >> cow[i][0] >> cow[i][1];
		if (cow[i][1] < min_s) {
			for (int j = 0; j < count; ++j) {
				slowest[j] = -1;
			}
			min_s = cow[i][1];
			slowest[0] = i;
			count = 1;
		}
		else if (cow[i][1] == min_s) {
			slowest[count] = i;
			++count;
		}
	}

	//cout << count << "\n";
	for (int i = 1; i < count; ++i) {
		if (cow[slowest[i]][0] - cow[slowest[i - 1]][0] == slowest[i] - slowest[i - 1]) {
			--count;
		}
	}
	fout << count << "\n";
}
*/