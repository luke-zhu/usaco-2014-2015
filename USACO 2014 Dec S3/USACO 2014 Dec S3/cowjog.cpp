#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, t, groups;
pair<int, int> cow[100000];

int main() {
	ofstream fout("cowjog.out");
	ifstream fin("cowjog.in");

	fin >> n >> t;
	for (int i = 0; i < n; ++i) {
		fin >> cow[i].first >> cow[i].second;
	}
	sort(cow, cow + n);

	groups = 1;
	for (int i = n - 1; i > 0; --i) {
		if ((long long)(t * (cow[i].second - cow[i - 1].second)) < cow[i].first - cow[i - 1].first) {
			++groups;
		}
	}
	fout << groups << "\n";
}