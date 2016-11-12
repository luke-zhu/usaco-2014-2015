#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ofstream fout("baseball.out");
	ifstream fin("baseball.in");
	
	int n;
	fin >> n;
	int pos[1000];
	for (int i = 0; i < n; ++i) {
		fin >> pos[i];
	}
	sort(pos, pos + n);
	int count;
	count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (pos[j] - pos[i] <= pos[k] - pos[j] && 2 * (pos[j] - pos[i]) >= pos[k] - pos[j]) {
					//cout << pos[i] << " " << pos[j] << " " << pos[k] << "\n";
					++count;
				}
			}
		}
	}
	fout << count << "\n";
}