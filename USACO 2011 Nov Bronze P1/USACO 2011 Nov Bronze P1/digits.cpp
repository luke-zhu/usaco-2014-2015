#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int to_decimal(string num, int base) {
	int decimal_val;
	decimal_val = 0;
	for (int i = 0; i < num.length(); ++i) {
		decimal_val = base * decimal_val + num[i] - 48;
	}
	return decimal_val;
}

int main() {
	ofstream fout("digits.out");
	ifstream fin("digits.in");

	string binary_num, ternary_num;
	fin >> binary_num >> ternary_num;

	for (int i = 0; i < binary_num.length(); ++i) {
		string s;
		s = binary_num;
		if (s[i] = '0') {
			s[i] = '1';
		}
		else {
			s[i] = '0';
		}
		int val1;
		val1 = to_decimal(s, 2);
		for (int i = 0; i < ternary_num.length(); ++i) {
			string s1;
			s1 = ternary_num;
			if (ternary_num[i] != '0') {
				s1[i] = '0';
				int val2;
				val2 = to_decimal(s1, 3);
				if (val1 == val2) {
					cout << val1 << "\n";
					break;
				}
			}
			if (ternary_num[i] != '1') {
				s1[i] = '1';
				int val2;
				val2 = to_decimal(s1, 3);
				if (val1 == val2) {
					cout << val1 << "\n";
					break;
				}
			}
			if (ternary_num[i] != '2') {
				s1[i] = '2';
				int val2;
				val2 = to_decimal(s1, 3);
				if (val1 == val2) {
					cout << val1 << "\n";
					break;
				}
			}
		}
	}
}