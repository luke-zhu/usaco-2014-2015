#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> cows[50000];
bool crowded_ol[50000];

int main() {
	ifstream cin("crowded.in");
	ofstream cout("crowded.out");

	int n, d;
	cin >> n >> d;

	for (int i = 0; i < n; ++i) {
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows, cows + n);

	priority_queue<pair<int, int>> on_left; //(height, position)
	for (int i = 0; i < n; ++i) {
		while (!on_left.empty()) {
			if (cows[i].first - on_left.top().second <= d) {
				if (on_left.top().first >= 2 * cows[i].second) {
					crowded_ol[i] = true;
				}
				break;
			}
			else {
				on_left.pop();
			}
		}
		on_left.push(pair<int, int>(cows[i].second, cows[i].first));
	}

	int num_crowded = 0;

	priority_queue<pair<int, int>> on_right;
	for (int i = n - 1; i >= 0; --i) {
		while (!on_right.empty() && crowded_ol[i]) {
			if (on_right.top().second - cows[i].first<= d) {
				if (on_right.top().first >= 2 * cows[i].second) {
					++num_crowded;
				}
				break;
			}
			else {
				on_right.pop();
			}
		}
		on_right.push(pair<int, int>(cows[i].second, cows[i].first));
	}
	cout << num_crowded << "\n";

	/*
	for (int i = 0; i < n; ++i) {
		cout << cows[i].first << " " << crowded_ol[i] << "\n";
	}
	*/
}