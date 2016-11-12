#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector < long long > interesting;

int string_val_cmp(string s1, long long i2) {
	ostringstream convert;
	string s2;
	convert << i2;
	s2 = convert.str();

	if (s1.length() < s2.length()) {
		return -1;
	}
	else if (s1.length() > s2.length()) {
		return 1;
	}
	else {
		return s1.compare(s2);
	}
}

void to_interesting(int len, int a, int b) {
	if (a == b) {
		return;
	}

	else if (a == 0) {
		long long inter;
		inter = b;
		for (int i = 1; i < len; ++i) {
			inter = 10 * inter + a;
		}
		interesting.push_back(inter);
		return;
	}

	else if (b == 0) {
		for (int i = 1; i < len; ++i) {
			long long inter;
			inter = a;
			for (int j = 1; j < len; ++j) {
				if (i == j) {
					inter = 10 * inter + b;
				}
				else {
					inter = 10 * inter + a;
				}
			}
			interesting.push_back(inter);
		}
		return;
	}

	else {
		for (int i = 0; i < len; ++i) {
			long long inter;
			inter = 0;
			for (int j = 0; j < len; ++j) {
				if (i == j) {
					inter = 10 * inter + b;
				}
				else {
					inter = 10 * inter + a;
				}
			}
			interesting.push_back(inter);
		}
		return;
	}
}

int main() {
	ofstream fout("odometer.out");
	ifstream fin("odometer.in");

	string x, y;
	fin >> x >> y;

	for (unsigned int i = x.length(); i <= y.length(); ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				to_interesting(i, j, k);
			}
		}
	}

	for (unsigned int i = 0; i < interesting.size(); ++i) {
	}

	int total;
	total = 0;
	for (unsigned int i = 0; i < interesting.size(); ++i) {
		if (string_val_cmp(x, interesting[i]) <= 0 && string_val_cmp(y, interesting[i]) >= 0) {
			++total;
		}
	}
	fout << total << "\n";
}