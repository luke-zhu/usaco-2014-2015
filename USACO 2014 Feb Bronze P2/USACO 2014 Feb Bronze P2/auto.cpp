#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ofstream fout("auto.out");
	ifstream fin("auto.in");

	int w, n;
	array < string, 10000 > words, sorted_words;
	array <string, 1000 > partial;
	for (int i = 0; i < w; ++i) {
		fin >> words[i];
		sorted_words[i] = words[i];
	}
	sort(sorted_words.begin(), sorted_words.end());
	for (int i = 0; i < n; ++i) {
		fin >> partial[i];
	}

	for (int i = 0; i < n; ++i) {
		array <string, 1000>::iterator it;
		for (int )
	}
}