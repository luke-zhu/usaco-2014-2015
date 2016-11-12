#include <iostream>
#include <fstream>

using namespace std;

int n, m, q, rev[100001], pos[5000];

int find(int pos, int moves) {
	cout << pos << " " << moves << "\n";
	if (moves == 0) {
		return pos;
	}
	if (pos + 1 > m) {
		return find(pos + 1, moves - 1);
	}
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

	for (int i = 0; i < 1; ++i) {
		cin >> pos[i];
		cout << pos[i] << "\n";
		if (pos[i] <= n - m) {
			cout << find(n + 1 - pos[i] - m, n + 1 - m) << "\n";
			//cout << "B Done\n";
		}
		else {
			cout << find(rev[1], n - pos[i]) << "\n";
			//cout << "C Done\n";
		}
	}
}