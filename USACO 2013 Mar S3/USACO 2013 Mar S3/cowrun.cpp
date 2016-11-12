#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, location[1000];

int main() {
	ofstream fout("cowrun.out");
	ifstream fin("cowrun.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> location[i];
	}
	sort(location, location + n);

	for (int )
}