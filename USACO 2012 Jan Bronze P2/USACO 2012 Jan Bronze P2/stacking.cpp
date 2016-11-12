#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
	ofstream fout("stacking.out");
	ifstream fin("stacking.in");

	int n, k;
	cin >> n >> k;
	array < int, 1000000 > stacks;
	for (int i = 0; i < k; ++i) {
		int l, u;
		cin >> l >> u;
		for (int j = l; j <= u; ++i) {
			++stacks[j];
		}
	}
	sort(stacks.begin(), stacks.end());
	cout << stacks[n / 2 + 1];
}