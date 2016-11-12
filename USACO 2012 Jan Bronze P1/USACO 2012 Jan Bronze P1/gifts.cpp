#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool coupon_sort(pair <int, int > a, pair <int, int > b) {
	return a.second > b.second;
}

int main() {
	/*
	ofstream fout("gifts.out");
	ifstream fin("gifts.in");

	int g, b;
	fin >> g >> b;
	pair <int, int> cost[1000]; // w/o coupon, w/ coupon;
	for (int i = 0; i < g; ++i) {
		int p, s;
		fin >> p >> s;
		cost[i] = pair <int, int>(p + s, p / 2 + s);
	}
	sort(cost, cost + g);
	cout << "clear input/sort\n";
	
	for (int i = 0, spent = 0; i < g; ++i) {
		spent += cost[i].first;
		if (spent > b) {
			sort(cost, cost + i + 1, coupon_sort);
			if (spent < cost[0].second) {
				cout << i + 1 << "\n";
				return 1;
			}
			cout << i << "\n";
			return 0;
		}
	}
	cout << g << "\n";
	*/
}