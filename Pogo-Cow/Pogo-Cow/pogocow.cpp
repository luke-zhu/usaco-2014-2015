#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> cows[1000];

int max_points(int curr_i, int curr_p, int curr_hop) {
	int max_p = curr_p;
	for (int i = curr_i + 1; i < n; ++i) {
		if (cows[i].first - cows[curr_i].first >= curr_hop) {
			max_p = max(max_p, max_points(i, curr_p + cows[i].second, cows[i].first - cows[curr_i].first));
		}
	}
}

int main() {
	ifstream cin("pogocow.in");
	ofstream cout("pogocow.out");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cows[i].first >> cows[i].second;
	}
}