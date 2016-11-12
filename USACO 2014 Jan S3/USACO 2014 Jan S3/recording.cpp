#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>

using namespace std;

int n, dp[150][150][150];
pair <int, int> show[150];

int main() {
	ofstream fout("recording.out");
	ifstream fin("recording.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> show[i].first >> show[i].second;
	}
	sort(show, show + n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++i) {
			for 
		}
	}
}