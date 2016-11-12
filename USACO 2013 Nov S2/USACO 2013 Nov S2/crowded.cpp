#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

int n, d, num;
pair < int, int > cow[50000];
priority_queue < pair < int, int > > heap, rev_heap;
bool left_towered[50000], right_towered[50000];

int main() {
	ofstream fout("crowded.out");
	ifstream fin("crowded.in");

	fin >> n >> d;
	for (int i = 0; i < n; ++i) {
		fin >> cow[i].first >> cow[i].second;
	}
	sort(cow, cow + n);

	for (int i = 0; i < n; ++i) {
		while (!heap.empty()) {
			if (cow[i].first - heap.top().second <= d) {
				if (heap.top().first >= 2 * cow[i].second) {
					left_towered[i] = true;
				}
				break;
			}
			heap.pop();
		}
		heap.push(pair < int, int >(cow[i].second, cow[i].first));
		//cout << heap.top().second << "\n";
	}
	
	for (int i = n - 1; i >= 0; --i) {
		while (!rev_heap.empty()) {
			if (rev_heap.top().second - cow[i].first <= d) {
				if (rev_heap.top().first >= 2 * cow[i].second) {
					right_towered[i] = true;
				}
				break;
			}
			rev_heap.pop();
		}
		rev_heap.push(pair < int, int >(cow[i].second, cow[i].first));
	}

	for (int i = 0; i < n; ++i) {
		if (left_towered[i] && right_towered[i]) {
			++num;
		}
	}
	fout << num << "\n";
}