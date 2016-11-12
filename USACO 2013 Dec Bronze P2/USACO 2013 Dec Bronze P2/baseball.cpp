#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, pos[1000];

int main()
{
	ofstream fout("baseball.out");
	ifstream fin("baseball.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> pos[i];
	}
	sort(pos, pos + n);

	int count;
	count = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			int first;
			first = pos[j] - pos[i];
			for (int k = j + 1; k < n; ++k) {
				int second;
				second = pos[k] - pos[j];
				if (first <= second && 2 * first >= second) {
					++count;
				}
			}
		}
	}
	cout << count << "\n";
}