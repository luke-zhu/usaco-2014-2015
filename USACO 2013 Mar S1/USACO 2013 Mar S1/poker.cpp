#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, card[100000];
long long hands;

int main() {
	ofstream fout("poker.out");
	ifstream fin("poker.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> card[i];
	}

	hands = card[0];
	for (int i = 1; i < n; ++i) {
		if (card[i] > card[i - 1]) {
			hands += card[i] - card[i - 1];
		}
	}
	fout << hands << "\n";
}