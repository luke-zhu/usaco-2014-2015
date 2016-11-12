#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("records.out");
	ifstream fin("records.in");

	int n;
	fin >> n;
	string group[1000];
	for (int i = 0; i < n; ++i) {
		string cow[3];
		fin >> cow[0] >> cow[1] >> cow[2];
		sort(cow, cow + 3);
		group[i] = cow[0];
		group[i] += " ";
		group[i] += cow[1];
		group[i] += " ";
		group[i] += cow[2];
	}
	sort(group, group + n);

	string last;
	int count, max_count;
	last = "";
	max_count = 0;
	count = 1;
	for (int i = 0; i < n; ++i) {
		if (last.compare(group[i]) == 0) {
			++count;
		}
		else {
			if (count > max_count) {
				max_count = count;
			}
			count = 1;
			last = group[i];
		}
	}
	if (count > max_count) {
		max_count = count;
	}
	fout << max_count << "\n";
}