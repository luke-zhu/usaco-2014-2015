#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <algorithm>

using namespace std;

int n;
array < int, 100 > array_a;
map < int, int > map_b;

int cyclic_shift(int index) {
	// If the index equals the mapped index of its value
	if (index == map_b[array_a[index]]) {
		return 1;
	}
	int temp;
	// The displaced value
	temp = array_a[map_b[array_a[index]]];
	// The value is shifted to the correct index
	array_a[map_b[array_a[index]]] = array_a[index];
	array_a[index] = temp;
	return 1 + cyclic_shift(index);
}

int main() {
	ofstream fout("reorder.out");
	ifstream fin("reorder.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> array_a[i];
	}
	for (int i = 0; i < n; ++i) {
		int k;
		fin >> k;
		map_b.insert(pair < int, int >(k, i));
	}

	int num_shifts, max_length;
	num_shifts = 0; max_length = 0;
	for (int i = 0; i < n; ++i) {
		int length;
		length = cyclic_shift(i);
		if (length - 1) {
			++num_shifts;
			max_length = max(max_length, length);
		}
	}

	cout << num_shifts << " " << max_length << "\n";
}