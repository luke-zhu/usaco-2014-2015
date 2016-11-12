#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("nocow.out");
	ifstream fin("nocow.in");

	int n, k;
	fin >> n >> k;
	string farmer, john, has, no, adj[30][100];
	fin >> farmer >> john >> has >> no;
	int num_adj;
	num_adj = 0;
	string s;
	fin >> s;
	cout << s << "\n";
	while (s != "cow.") {
		adj[num_adj][0] = s;
		++num_adj;
		//cout << num_adj << "\n";
		fin >> s;
		//cout << s << "\n";
	}
	//cout << "clear_A" << "\n";

	for (int i = 1; i < n; ++i) {
		fin >> farmer >> john >> has >> no;
		for (int j = 0; j < num_adj; ++j) {
			for (int k = 0; k < 100; ++k) {

			}
		}
	}
	
	for (int i = )
}