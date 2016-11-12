#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fout("cowrace.out");
	ifstream fin("cowrace.in");

	pair < int, int > bessie[1000], elsie[1000]; // (speed, time)

	int n, m;
	fin >> n >> m;
	int culum_t;
	culum_t = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		fin >> bessie[i].first >> t;
		culum_t += t;
		bessie[i].second = culum_t;
	}
	culum_t = 0;
	for (int i = 0; i < m; ++i) {
		int t;
		fin >> elsie[i].first >> t;
		culum_t += t;
		elsie[i].second = culum_t;
	}

	int i, j, curr_t, diff, old_diff, lead_changes;
	i = 0; j = 0; curr_t = 0; diff = 0; old_diff = 0; lead_changes = 0; // bessie(+) / elsie(-)
	while (i < n || j < m) {
		if (bessie[i].second < elsie[j].second) {
			diff += bessie[i].first * (bessie[i].second - curr_t) - elsie[j].first * (bessie[i].second - curr_t);
			curr_t = bessie[i].second;
			++i;
		}
		else {
			diff += bessie[i].first * (elsie[j].second - curr_t) - elsie[j].first * (elsie[j].second - curr_t);
			curr_t = elsie[j].second;
			if (bessie[i].second == elsie[j].second) {
				++i;
			}
			++j;
		}
		if (old_diff != diff) {
			//cout << old_diff << " " << diff << "\n";
			if (old_diff < 0 && diff > 0 || old_diff > 0 && diff < 0) {
				++lead_changes;
			}
			if (diff != 0) {
				old_diff = diff;
			}
		}
	}
	cout << lead_changes << "\n";
}