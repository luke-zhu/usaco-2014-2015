#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
	ifstream cin("empty.in");
	ofstream cout("empty.out");

	int n, k;
	cin >> n >> k;
	
	map<int, int> cows; //(stall: num_cows)
	for (int i = 0; i < n; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		for (int j = 1; j <= y; ++j) {
			if (cows.count(a * j + b)) {
				
			}
		}
	}
}