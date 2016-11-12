/*
ID: lukezhu1
PROG: preface
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int	numerals[7];
void make_numeral(int);

int main() {
	ofstream fout("preface.out");
	ifstream fin("preface.in");
	
	int n;
	fin >> n;
	for (int i = 1; i <= n; ++i) {
		make_numeral(i);
	}
	if (numerals[0])
		fout << "I " << numerals[0] << "\n";
	if (numerals[1])
		fout << "V " << numerals[1] << "\n";
	if (numerals[2])
		fout << "X " << numerals[2] << "\n";
	if (numerals[3])
		fout << "L " << numerals[3] << "\n";
	if (numerals[4])
		fout << "C " << numerals[4] << "\n";
	if (numerals[5])
		fout << "D " << numerals[5] << "\n";
	if (numerals[6])
		fout << "M " << numerals[6] << "\n";
}

void make_numeral(int num) {
	int avail[13] = { 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3 };
	while (num) {
		if (num >= 1000 && avail[12]) {
			++numerals[6];
			num -= 1000;
			--avail[12];
		}
		else if (num >= 900 && avail[11]) {
			++numerals[4];
			++numerals[6];
			num -= 900;
			--avail[11];
		}
		else if (num >= 500 && avail[10]) {
			++numerals[5];
			num -= 500;
			--avail[10];
		}
		else if (num >= 400 && avail[9]) {
			++numerals[4];
			++numerals[5];
			num -= 400;
			--avail[9];
		}
		else if (num >= 100 && avail[8]) {
			++numerals[4];
			num -= 100;
			--avail[8];
		}
		else if (num >= 90 && avail[7]) {
			++numerals[2];
			++numerals[4];
			num -= 90;
			--avail[7];
		}
		else if (num >= 50 && avail[6]) {
			++numerals[3];
			num -= 50;
			--avail[6];
		}
		else if (num >= 40 && avail[5]) {
			++numerals[2];
			++numerals[3];
			num -= 40;
			--avail[5];
		}
		else if (num >= 10 && avail[4]) {
			++numerals[2];
			num -= 10;
			--avail[4];
		}
		else if (num >= 9 && avail[3]) {
			++numerals[0];
			++numerals[2];
			num -= 9;
			--avail[3];
		}
		else if (num >= 5 && avail[2]) {
			++numerals[1];
			num -= 5;
			--avail[2];
		}
		else if (num >= 4 && avail[1]) {
			++numerals[0];
			++numerals[1];
			num -= 4;
			--avail[1];
		}
		else {
			++numerals[0];
			--num;
			--avail[0];
		}
	}
}