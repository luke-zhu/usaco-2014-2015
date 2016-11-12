#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ofstream fout("clumsy.out");
	ifstream fin("clumsy.in");

	string s;
	fin >> s;

	int balance, reversed;
	balance = 0;
	reversed = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			++balance;
		}
		else {
			--balance;
		}
		if (balance < 0) {
			//s[i] = '(';
			balance += 2;
			++reversed;
		}
		else if (balance > s.length() - i - 1) {
			//s[i] = ')';
			balance -= 2;
			++reversed;
		}
		//cout << s << " " << balance << "\n";
	}
	
	//cout << reversed << "\n";
	fout << reversed << "\n";
}