#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("haybales.out");
	ifstream fin("haybales.in");

	int n, heights[10000];
	fin >> n;
	int average;
	average = 0;
	for (int i = 0; i < n; ++i) {
		fin >> heights[i];
		average += heights[i];
	}
	average /= n;
	sort(heights, heights + n);

	int moves;
	moves = 0;
	for (int i = 0; i < n; ++i) {
		if (heights[i] >= average) {
			break;
		}
		moves += average - heights[i];
	}
	cout << moves << "\n";
}