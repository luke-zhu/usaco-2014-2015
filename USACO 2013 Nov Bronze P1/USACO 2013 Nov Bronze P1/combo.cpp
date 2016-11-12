#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, fjohn[3], master[3];

int distance(int a, int b) {
	return min(abs(b - a), n - abs(b - a));
}

int constant() {
	int count;
	count = 250;
	int inter;
	inter = (5 - min(abs(fjohn[0] - master[0]), n - abs(fjohn[0] - master[0])));
	inter *= (5 - min(abs(fjohn[1] - master[1]), n - abs(fjohn[1] - master[1])));
	inter *= (5 - min(abs(fjohn[2] - master[2]), n - abs(fjohn[2] - master[2])));
	if (inter > 0)
	{
		count -= inter;
	}
	return count;
}

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");

	cin >> n;
	cin >> fjohn[0] >> fjohn[1] >> fjohn[2];
	cin >> master[0] >> master[1] >> master[2];

	cout << constant();

}