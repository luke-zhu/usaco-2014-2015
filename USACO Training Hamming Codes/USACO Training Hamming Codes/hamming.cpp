/*
ID: lukezhu1
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string binary_str(int);
int pos_compare(string, string);
vector < int > hamming(int, vector < int >);

int n, b, d;

int main() {
	ofstream fout("hamming.out");
	ifstream fin("hamming.in");

	fin >> n >> b >> d;
	for (int i = 0; i < pow(2, b); ++i) {
		vector < int > empty_words, codewords;
		codewords = hamming(i,empty_words);
		//cout << codewords.size() << "\n";
		if (codewords.size() == n) {
			for (int j = 0; j < codewords.size(); ++j) {
				if (j % 10 == 0) {
					fout << codewords[j];
				}
				else if (j % 10 == 9) {
					fout << " " << codewords[j] << "\n";
				}
				else {
					fout << " " << codewords[j];
				}
			}
			if (codewords.size() % 10)
				fout << "\n";
			break;
		}
	}
}

vector < int > hamming(int num, vector < int > codewords) {
	if (num == pow(2, b + 1)) {
		return codewords;
	}
	else if (codewords.size() == n) {
		return codewords;
	}
	vector < int > copy_codewords;
	copy_codewords = codewords;
	bool difference;
	difference = true;
	for (int i = 0; i < codewords.size(); ++i) {
		if (pos_compare(binary_str(num), binary_str(codewords[i])) < d) {
			//cout << num << " " << codewords[i] << " ";
			//cout << binary_str(num) << " " << binary_str(codewords[i]) << "\n";
			difference = false;
			break;
		}
	}
	//cout << difference << "\n";
	if (difference) {
		copy_codewords.push_back(num);
		vector < int > completed_codewords;
		completed_codewords = hamming(num + 1, copy_codewords);
		if (completed_codewords.size() == n) {
			return completed_codewords;
		}
	}
	return hamming(num + 1, codewords);
}

string binary_str(int num) {
	//cout << num << " ";
	string s;
	s = "";
	for (int i = b - 1; i >= 0; --i) {
		int digit;
		digit = num / (int)pow(2, i);
		if (digit) {
			s.push_back('1');
		}
		else {
			s.push_back('0');
		}
		num -= digit * (int)pow(2, i);
	}
	//cout << s << "\n";
	return s;
}

int pos_compare(string s1, string s2) {
	int diff;
	diff = 0;
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] != s2[i]) {
			++diff;
		}
	}
	//cout << diff << "\n";
	return diff;
}