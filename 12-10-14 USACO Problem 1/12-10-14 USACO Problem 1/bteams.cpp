#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int cows[12];

bool swap(int team_a, int team_b) {
	int sum_a, sum_b;
	sum_a = cows[3 * team_a] + cows[3 * team_a + 1] + cows[3 * team_a + 2];
	sum_b = cows[3 * team_b] + cows[3 * team_b + 1] + cows[3 * team_b + 2];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (abs(sum_a - sum_b) > abs(sum_a - sum_b - 2 * cows[3 * team_a + i] + 2 * cows[3 * team_b + j])) {
				int temp;
				temp = cows[3 * team_a + i];
				cows[3 * team_a + i] = cows[3 * team_b + j];
				cows[3 * team_b + j] = temp;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ofstream fout("bteams.out");
	ifstream fin("bteams.in");

	for (int i = 0; i < 12; ++i) {
		fin >> cows[i];
	}

	bool change = true;
	while (change) {
		change = false;
		for (int i = 0; i < 3; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				if (swap(i, j)) {
					change = true;
					cout << "cycle\n";
					continue;
				}
			}
		}
	}
	//cout << cows[0] + cows[1] + cows[2] << "\n";
	//cout << cows[3] + cows[4] + cows[5] << "\n";
	//cout << cows[6] + cows[7] + cows[8] << "\n";
	//cout << cows[9] + cows[10] + cows[11] << "\n";
	int minimum, maximum;
	minimum = 4000000;
	maximum = 0;
	for (int i = 0; i < 4; ++i) {
		int sum;
		sum = cows[3 * i] + cows[3 * i + 1] + cows[3 * i + 2];
		if (sum < minimum) {
			minimum = sum;
		}
		if (sum > maximum) {
			maximum = sum;
		}
	}
	cout << maximum - minimum << "\n";
	fout << maximum - minimum << "\n";
}