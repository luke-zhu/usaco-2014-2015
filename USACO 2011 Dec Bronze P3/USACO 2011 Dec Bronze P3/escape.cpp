#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int n;
int weights[20];

int recursive_sol(int index, int num_cows, int curr_sum) {
	//cout << index << " " << num_cows << "\n";
	if (index == n) {
		//cout << "Index " << num_cows << "\n";
		return num_cows;
	}
	int a, b;
	a = weights[index]; b = curr_sum;
	while (b || a) {
		if (b % 10 + a % 10 > 9) {
			//cout << "Carry " << num_cows << "\n";
			return recursive_sol(index + 1, num_cows, curr_sum);
		}
		b /= 10; 
		a /= 10;
	}
	return max(recursive_sol(index + 1, num_cows, curr_sum), recursive_sol(index + 1, num_cows + 1, curr_sum + weights[index]));
}

int main() {
	ofstream fout("escape.out");
	ifstream fin("escape.in");

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> weights[i];
	}
	//cout << "Clear: Input\n";

	cout << recursive_sol(0, 0, 0) << "\n";
}