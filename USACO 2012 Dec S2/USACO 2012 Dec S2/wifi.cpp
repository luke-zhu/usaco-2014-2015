#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int location[2000];

int main() {
	ofstream fout("wifi.out");
	ifstream fin("wifi.in");

	int n;
	double a, b;
	fin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		fin >> location[i];
	}
	sort(location, location + n);

	double min_cost;
	min_cost = a;
	for (int i = 1; i < n; ++i) {
		min_cost += min(a, b * (location[i] - location[i - 1]) / 2);
	}
	fout << setprecision(9) << min_cost << "\n";
}