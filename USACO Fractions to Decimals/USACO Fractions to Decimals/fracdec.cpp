/*
ID: lukezhu1
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int r[100000][2];

string int_to_str(int i)
{
	ostringstream outstr;
	outstr << i;
	return outstr.str();
}

int main() {
	ofstream fout("fracdec.out");
	ifstream fin("fracdec.in");

	int n, d;
	fin >> n >> d;

	string s_int, s_dec;

	s_int = int_to_str(n / d);
	s_int.push_back('.');
	n %= d;
	r[n][0] = 1;
	r[n][1] = 0;
	n *= 10;

	int ind;
	ind = 1;
	while (1) {
		s_dec += int_to_str(n / d);
		n %= d;
		if (n == 0) {
			break;
		}
		if (r[n][0]) {
			s_dec.insert(r[n][1], 1, '(');
			s_dec.push_back(')');
			break;
		}
		else {
			r[n][0] = 1;
			r[n][1] = ind;
		}
		n *= 10;
		++ind;
	}
	string s;
	s = s_int + s_dec;
	while (s.length() > 76) {
		fout << s.substr(0, 76) << "\n";
		s = s.substr(76, s.length() - 76);
	}
	fout << s << "\n";
}