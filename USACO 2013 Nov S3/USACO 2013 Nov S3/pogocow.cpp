#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen("crowded.in", "r", stdin);
	// freopen("crowded.out", "w", stdout);

	int n;
	cin >> n;
	pair < int, int > target[1000];
	for (int i = 0; i < n; ++i) {
		cin >> target[i].first >> target[i].second;
	}
	sort(target, target + n);
}