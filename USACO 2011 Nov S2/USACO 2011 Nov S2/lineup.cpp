#include <iostream>
#include <fstream>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

int n, a, b, cost;
pair < int, int > cow[50000];
set < int > breeds, lineup;

int main() {
	ofstream fout("lineup.out");
	ifstream fin("lineup.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> cow[i].first >> cow[i].second;
		breeds.insert(cow[i].second);
	}
	sort(cow, cow + n);

	cost = 1000000000;
	for (int i = 0, j = 0; j < n; ++j) {
		lineup.insert(cow[j].second);
		while (i < j && cow[i].second == cow[j].second) {
			++i;
		}
		if (lineup.size() == breeds.size()) {
			cost = min(cost, cow[j].first - cow[i].first);
		}
	}
	cout << cost << "\n";
}