#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct cow {
	int height, weight, strength;
};

bool cow_pred(cow a, cow b) {
	if (cow)
}

int main() {
	ofstream cout("guard.out");
	ifstream cin("guard.in");

	int n, h;
	cin >> n >> h;

	cow cows[20];
	for (int i = 0; i < n; ++i) {
		cin >> cows[i].height >> cows[i].weight >> cows[i].strength;
	}

	sort(cows, cows + n);
}