#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, l;
pair<int, int> book[2000];

int main() {
	ofstream fout("bookshelf.out");
	ifstream fin("bookshelf.in");

	fin >> n >> l;
	for (int i = 0; i < n; ++i) {
		fin >> book[i].first >> book[i].second;
	}
	sort(book, book + n);

	for (int i = 0; i < n; ++i) {
	}
}