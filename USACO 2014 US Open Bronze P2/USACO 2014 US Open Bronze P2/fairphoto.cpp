#include <iostream>
#include <fstream>
#include <array>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("fairphoto.out");
	ifstream fin("fairphoto.in");

	int n;
	array < pair < int, char >, 100000 > cows;

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.begin() + n);

	int size, max_size, num_h, num_g;
	size = 0; max_size = 0; num_h = 0; num_g = 0;
	deque < pair < int, char > > photo_range;
	photo_range.push_back(cows[0]);

	for (int i = 1; i < n; ++i) {
		if (cows[i].second == 'G') {
			++num_g;
		}
		else {
			++num_h;
		}
		photo_range.push_back(cows[i]);
		size += cows[i].first - cows[i - 1].first;

		while (num_h != num_g && photo_range.size() > 1) {
			size -= photo_range[1].first - photo_range[0].first;
			if (photo_range[0].second == 'G') {
				--num_g;
			}
			else {
				--num_h;
			}
			photo_range.pop_front();
		}
		if (num_h == num_g) {
			min_size = min(min_size, size);
		}
	}
	cout << min_size << "\n";
}