#include <iostream>
#include <fstream>

using namespace std;

int n, m, q, rev[100001], pos[5000];

int find(int pos, int moves) {
	return find(rev[pos + 1], moves - 1);
}

int main() {
	ifstream cin("shuffle.in");
	//ofstream cout("shuffle.out");

	cin >> n >> m >> q;
	for (int i = 1; i <= m; ++i) {
		int temp;
		cin >> temp;
		rev[temp] = i;
	}

	for (int i = 0; i < q; ++i) {
		cin >> pos[i];
		if (pos[i] < m) {
			cout << find(n + 1 - pos[i] - m, n + 1 - m) << "\n";
		}
	}
}