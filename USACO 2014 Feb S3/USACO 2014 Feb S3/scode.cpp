#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int reverse(string s) {
	if (s.length() == 2) {
		return 1;
	}
	int total;
	total = 
	if (s.length() % 2 == 0) {
		for (int i = 1; i <= s.length() / 2 - 1; ++i) {
			if (s.substr(0, i) == s.substr(i, i)) {
				total += reverse(s.substr(i, s.length() - i));
			}
		}
		for (int i = 1; i <= s.length() / 2 - 1; ++i) {
			if (s.substr(0, i) == s.substr(s.length() - i, i)) {
				total += reverse(s.substr(i, s.length() - i));
				total += reverse(s.substr(0, s.length() - i));
			}
		}
		for (int i = 1; i <= s.length() / 2 - 1; ++i) {
			if (s.substr(s.length() - i, i) == s.substr(s.length() - 2 * i, i)) {
				total += reverse(s.substr(s.length() - 2 * i, s.length() - i));
			}
		}
	}
	else {
		for (int i = 1; i <= s.length() / 2; ++i) {
			if (s.substr(0, i) == s.substr(i, i)) {
				total += reverse(s.substr(i, s.length() - i));
			}
		}
		for (int i = 1; i <= s.length() / 2; ++i) {
			if (s.substr(0, i) == s.substr(s.length() - i, i)) {
				total += reverse(s.substr(i, s.length() - i));
				total += reverse(s.substr(0, s.length() - i));
			}
		}
		for (int i = 1; i <= s.length() / 2; ++i) {
			if (s.substr(s.length() - i, i) == s.substr(s.length() - 2 * i, i)) {
				total += reverse(s.substr(s.length() - 2 * i, s.length() - i));
			}
		}
	}
	return total;
}

int main() {
	ofstream fout("scode.out");
	ifstream fin("scode.in");

	string s;
	fin >> s;
	fout << reverse(s) - 1 << "\n";
}