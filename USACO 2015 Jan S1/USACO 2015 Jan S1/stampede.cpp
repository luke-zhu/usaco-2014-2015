#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>

using namespace std;

struct Cow {
	int y, start, end;
} cow[50000];

typedef pair<int, int> pii;

int n, num_seen, seen[50000];
set <int> points;
priority_queue <pii, vector<pii>, greater<pii>> pq;

bool compare(Cow a, Cow b) {
	return a.y < b.y;
}

int main() {
	ofstream fout("stampede.out");
	ifstream fin("stampede.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		int x, r;
		fin >> x >> cow[i].y >> r;
		cow[i].start = (-1 - x) * r;
		cow[i].end = -x * r;
		points.insert(cow[i].start);
		points.insert(cow[i].end);
	}
	sort(cow, cow + n, compare);

	for (int i = 0; i < n; ++i) {
		set<int>::iterator it = points.lower_bound(cow[i].start);
		if (it != points.end() && *it < cow[i].end) {
			++num_seen;
			points.erase(points.lower_bound(cow[i].start), points.lower_bound(cow[i].end));
		}
	}
	fout << num_seen << "\n";
}