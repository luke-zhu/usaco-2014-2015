#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ofstream fout("folding.out");
	ifstream fin("folding.in");

	int n, l;
	fin >> n >> l;
	int knots[100];
	for (int i = 0; i < n; ++i) {
		fin >> knots[i];
	}
	sort(knots, knots + n);
	/*
	for (int i = 0; i < n; ++i) {
		cout << knots[i] << "\n";
	}
	cout << "\n";
	*/
	int lengths[99];
	for (int i = 0; i < n - 1; ++i) {
		lengths[i] = knots[i + 1] - knots[i];
	}
	/*
	for (int i = 0; i < n - 1; ++i) {
		cout << lengths[i] << "\n";
	}
	*/
	int points;
	points = 2;
	for (int i = 1; i < n - 1; ++i) {
		int smaller;
		//cout << i << " " << n - i - 1 << "\n";
		smaller = min(i, n - i - 1);
		bool aligned;
		aligned = true;
		for (int j = 1; j <= smaller; ++j) {
			if (lengths[i + j] != lengths[i - j]) {
				aligned = false;
				break;
			}
		}
		if (aligned) {
			//cout << knots[i] << "\n";
			++points;
		}
	}
	for (int i = 1; i < n - 3; ++i) {
		int smaller;
		smaller = min(i, n - i - 1);
		bool aligned;
		aligned = true;
		for (int j = 1; j < smaller; ++j) {
			//cout << i + j + 1 << " " << i - j << "\n";
			if (lengths[i + j + 1] != lengths[i - j]) {
				//cout << lengths[4] << "\n";
				//cout << "* " << lengths[i + j + 1] << " " << lengths[i - j] << "\n";
				aligned = false;
				break;
			}
		}
		if (aligned) {
			//cout << knots[i] << "\n";
			++points;
		}
	}
	cout << points << "\n";
}