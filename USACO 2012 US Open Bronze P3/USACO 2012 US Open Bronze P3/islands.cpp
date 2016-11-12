#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>

using namespace std;

int heights[100000], num_vals;
pair < int, int > valleys[49999];

int main()
{
	ofstream fout("islands.out");
	ifstream fin("islands.in");

	int n; //Get inputs
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> heights[i];
	}

	num_vals = 0; //Get valleys
	for (int i = 1; i < n - 1; ++i) {
		int x;
		x = heights[i];
		if ((x < heights[i + 1]) && (x < heights[i - 1])) {
			valleys[num_vals].first = x;
			valleys[num_vals].second = min(heights[i + 1], heights[i - 1]);
			++num_vals;
		}
	}
	
	sort(valleys, valleys + num_vals + 1); //Sort

	deque < int > peaks;
	for (int i = 0; i <= num_vals; ++i) {
		int last;
		last = peaks[peaks.size() - 1];
		if (valleys[i].first != last) {
			for (int j = 0; j < peaks.size(); j++) {
				if (peaks[j] <= last) {
					
				}
			}
		}
		else {
			
		}
	}
	max_count = max(max_count, count);

	fout << max_count;
}