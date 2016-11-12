#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, notes[20000], c, chord[10];

bool ruminant(int start) {
	int curr[10];
	for (int i = 0; i < c; ++i) {
		curr[i] = notes[start + i];
	}
	sort(curr, curr + c);
	/*
	for (int i = 0; i < c; ++i) {
		cout << curr[i] << " ";
	}
	cout << "\n";
	*/
	int difference;
	difference = chord[0] - curr[0];
	for (int i = 1; i < c; ++i) {
		if (chord[i] - curr[i] != difference) {
			return false;
		}
	}
	return true;
}

int main() {
	ofstream fout("moosick.out");
	ifstream fin("moosick.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> notes[i];
	}
	fin >> c;
	if (c == 1) {
		fout << n << "\n";
		for (int i = 0; i < n; ++i) {
			fout << i << "\n";
		}
	}
	
	for (int i = 0; i < c; ++i) {
		fin >> chord[i];
	}
	sort(chord, chord + c);

	int sequences[20000], index;
	index = 0;
	for (int i = 0; i < n - c + 1; ++i) {
		if (ruminant(i)) {
			sequences[index] = i;
			++index;
		}
	}
	fout << index << "\n";
	for (int i = 0; i < index; ++i) {
		fout << sequences[i] + 1 << "\n";
	}
}