#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
	ifstream cin("recording.in");
	ofstream cout("recording.out");

	int n;
	cin >> n;
	pair<int, int> programs[150];
	set<int> times;
	for (int i = 0; i < n; ++i) {
		cin >> programs[i].first >> programs[i].second;
		times.insert(programs[i].first);
		times.insert(programs[i].second);
	}


}