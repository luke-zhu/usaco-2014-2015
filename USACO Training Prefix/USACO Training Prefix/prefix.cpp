/*
ID: lukezhu1
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool len[200001];

int main() {
	ofstream fout("prefix.out");
	ifstream fin("prefix.in");

	string s;
	string prim[200];
	int num_prim = 0;
	fin >> s;
	while (s != ".") {
		prim[num_prim] = s;
		++num_prim;
		fin >> s;
	}
	string seq;
	while (fin >> s) {
		seq.append(s);
	}
	/*
	for (int i = 0; i < num_prim; ++i) {
	cout << prim[i] << " ";
	}
	cout << "\n";
	cout << seq << "\n";
	cout << "\n";
	*/
	len[0] = true;
	for (int i = 0; i < seq.length(); ++i) {
		if (len[i]) {
			for (int j = 0; j < num_prim; ++j) {
				//cout << seq.substr(i, prim[j].length()) << " " << prim[j] << " ";
				if (seq.substr(i,prim[j].length()) == prim[j]) {
					//cout << "EQUAL" << "\n";
					//cout << i + prim[j].length() << "\n";
					len[i + prim[j].length()] = true;
				}
				//cout << "\n";
			}
		}
	}
	for (int i = seq.length(); i >= 0; --i) {
		if (len[i]) {
			fout << i << "\n";
			break;
		}
	}
}