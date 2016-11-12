#include <iostream> // 40 min O(N log N)
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("records.out");
	ifstream fin("records.in");

	int n;
	fin >> n;

	string groups[1000][3];
	string sorted[1000];
	for (int i = 0; i < n; ++i)
	{
		fin >> groups[i][0] >> groups[i][1] >> groups[i][2];
		sort(groups[i], groups[i] + 3);
		sorted[i] = groups[i][0] + groups[i][1] + groups[i][2];
	}
	sort(sorted, sorted + n);

	string last = { "" };
	int count, max_count;
	count = 0, max_count = 0;
	for (int i = 0; i < n; ++i) {
		if (sorted[i] != last) {
			max_count = max(max_count, count);
			last = sorted[i];
			count = 1;
		}
		else {
			++count;
		}
	}
	max_count = max(max_count, count);
	cout << max_count;
}