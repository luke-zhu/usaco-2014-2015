#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int w, n;
pair < string, int > word[1000000], partial[1000];

int main() {
	ofstream fout("auto.out");
	ifstream fin("auto.in");

	fin >> w >> n;
	for (int i = 0; i < w; ++i) {
		fin >> word[i].first;
		word[i].second = i;
	}
	for (int i = 0; i < n; ++i) {
		fin >> partial[i].second >> partial[i].first;
	}
	sort(word, word + w);

	for (int i = 0; i < n; ++i) {
		int curr_ind;
		curr_ind = 0;
		for (int j = 0; j < w; ++j) {
			if (word[j].first.length() < partial[i].first.length()) {
				continue;
			}
			if (word[j].first.compare(0, partial[i].first.length(), partial[i].first) == 0) {
				++curr_ind;
				if (curr_ind == partial[i].second) {
					fout << word[j].second + 1 << "\n";
					break;
				}
			}
		}
		if (curr_ind < partial[i].second) {
			fout << -1 << "\n";
		}
	}
}