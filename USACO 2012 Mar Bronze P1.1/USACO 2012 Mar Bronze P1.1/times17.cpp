#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("times17.out");
	ifstream fin("times17.in");

	string n;
	fin >> n;
	string s;
	s = n.substr(n.length() - 4, 4);
	bool carry;
	carry = false;
	for (int i = n.length() - 1; i >= 4; --i) {
		if (n[i] == '1' && n[i - 4] == '1') {
			if (carry) {
				s = '1' + s;
			}
			else {
				s = '0' + s;
				carry = true;
			}
		}
		else if (n[i] == '1' || n[i - 4] == '1') {
			if (carry) {
				s = '0' + s;
			}
			else {
				s = '1' + s;
			}
		}
		else {
			if (carry) {
				s = '1' + s;
				carry = false;
			}
			else {
				s = '0' + s;
			}
		}
		//cout << s << "\n";
	}
	for (int i = 3; i >= 0; --i) {
		if (n[i] == '1') {
			if (carry) {
				s = '0' + s;
			}
			else {
				s = '1' + s;
			}
		}
		else {
			if (carry) {
				s = '1' + s;
				carry = false;
			}
			else {
				s = '0' + s;
			}
		}
		//cout << s << "\n";
	}
	cout << s << "\n";
}