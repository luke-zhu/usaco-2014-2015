#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int cow[100000][2];

int main() {
	ofstream fout("cowjog.out");
	ifstream fin("cowjog.in");

	int n;
	fin >> n;
	fin >> cow[0][0] >> cow[0][1];
	for (int i = 1; i < n; ++i) {
		fin >> cow[i][0] >> cow[i][1];
	}

	int groups;
	groups = 1;
	for (int i = n - 1; i > 0; --i) {
		if (cow[i][1] >= cow[i - 1][1]) {
			++groups;
		}
		else {
			cow[i - 1][1] = cow[i][1];
		}
	}
	fout << groups << "\n";
}