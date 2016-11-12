#include <iostream>
#include <fstream>
#include <algorithm>	

using namespace std;

int n, last, max_dist;
pair < int, int > d[100000];
pair < int, char > cow[100000];

int main() {
	ofstream fout("fairphoto.out");
	ifstream fin("fairphoto.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> cow[i].first >> cow[i].second;
	}
	sort(cow, cow + n);
	for (int i = 0; i < n; ++i) {
		cout << cow[i].first << " " << cow[i].second << "\n";

	}
	cout << "\n";

	if (cow[0].second == 'W') {
		++d[0].first;
	}
	else {
		--d[0].first;
	}
	d[0].second = cow[0].first;
	for (int i = 1; i < n; ++i) {
		if (cow[i].second == 'W') {
			d[i].first = d[i - 1].first + 1;
		}
		else {
			d[i].first = d[i - 1].first - 1;
		}
		d[i].second = cow[i].first;
	}
	sort(d, d + n);
	for (int i = 0; i < n; ++i) {
		cout << d[i].second << " " << d[i].first << "\n";

	}
	cout << "\n";


	for (int i = 1; i < n; ++i) {
		if (d[i].first != d[last].first) {
			if (d[i - 1].second - d[last].second > max_dist) {
				max_dist = d[i - 1].second - d[last].second;
			}
			last = i;
		}
	}
	cout << max_dist << "\n";
}