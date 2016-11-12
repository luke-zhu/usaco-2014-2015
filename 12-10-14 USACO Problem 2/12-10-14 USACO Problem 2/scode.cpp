#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int recurse(string s) {
	//cout << s << "\n";
	if (s.length() % 2 == 0) {
		return 1;
	}
	int sum;
	sum = 0;
	string s1, s2, s3, s4;
	s1 = s.substr(0, s.length() / 2);
	s2 = s.substr(1, s.length() / 2);
	s3 = s.substr(s.length() / 2, s.length() / 2);
	s4 = s.substr(s.length() / 2 + 1, s.length() / 2);
	//cout << s1 << " " << s2 << " " << s3 << " " << s4 << "\n";
	if (s1.compare(s4) == 0) {
		sum += recurse(s.substr(0, s.length() / 2 + 1));
	}
	if (s2.compare(s4) == 0) {
		sum += recurse(s.substr(0, s.length() / 2 + 1));
	}
	if (s1.compare(s3) == 0) {
		sum += recurse(s.substr(s.length() / 2, s.length() / 2 + 1));
	}
	if (s1.compare(s4) == 0) {
		sum += recurse(s.substr(s.length() / 2, s.length() / 2 + 1));
	}
	return 1 + sum;
}

int main() {
	ofstream fout("scode.out");
	ifstream fin("scode.in");

	string s;
	fin >> s;
	fout << recurse(s) - 1 << "\n";
}