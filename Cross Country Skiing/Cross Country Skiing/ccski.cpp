#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin("ccski.in");
	//ofstream cout("ccski.out");

	int m, n;
	cin >> m >> n;

	int el[500][500], wp[500][500];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> el[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> wp[i][j];
		}
	}
}