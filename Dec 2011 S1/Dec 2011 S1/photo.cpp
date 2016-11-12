#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fout("photo.out");
	ifstream fin("photo.in");

	int n, ordering[20000][5];
	fin >> n;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> ordering[j][i];
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ordering[j][i] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int count;
			count = 1;
			for (int k = 1; k < 5; ++i) {
				if ()
			}
		}
	}
}