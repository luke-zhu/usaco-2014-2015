#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("clumsy.out");
	ifstream fin("clumsy.in");

	string s;
	fin >> s;

	int net_in;
	net_in = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			++net_in;
		}
		else {
			--net_in;
		}
	}
	for (int i = 0; i < s)
}