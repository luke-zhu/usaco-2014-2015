/*
ID: lukezhu1
PROG: shopping
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int offers[99][5];

int main() {

	ifstream cin("shopping.in");
	//ofstream cout("shopping.out");

	//Input
	int s;
	cin >> s;

	map<int, int> code;
	int num_products = 0, price[99];
	for (int i = 0; i < s; ++i) {

		int n;
		cin >> n;

		for (int j = 0; j < n; ++j) {

			int c, k;
			cin >> c >> k;

			if (!code.count(c)) {
				code[c] = ++num_products;
			}
			offers[i][code[c]] = k;
		}

		cin >> price[i];
	}

	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < num_products; ++j) {
			cout << offers[i] << " ";
		}
		cout << "\n";
	}

	int b;
	cin >> b;
}