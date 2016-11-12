/*
ID: lukezhu1
PROG: spin
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int speed[5], wedge[5][360], curr_wedge[5][360];

int main() {
	ifstream cin("spin.in");
	ofstream cout("spin.out");

	for (int i = 0; i < 5; ++i) {
		cin >> speed[i];
		int w;
		cin >> w;
		for (int j = 0; j < w; ++j) {
			int start, extent;
			cin >> start >> extent;
			++extent;
			for (int k = start; extent--; k = (k + 1) % 360) {
				wedge[i][k] = 1;
			}
		}
	}

	//cout << "clear 1\n";

	int t = 0;
	while (t < 360) {
		for (int i = 0; i < 360; ++i) {
			for (int j = 0; j < 5; ++j) {
				curr_wedge[j][(i + t * speed[j]) % 360] = wedge[j][i];
			}
		}
		for (int i = 0; i < 360; ++i) {
			bool flag = true;
			for (int j = 0; j < 5; ++j) {
				if (!curr_wedge[j][i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << t << "\n";
				return 0;
			}
		}
		++t;
		//cout << t << "\n";
	}
	cout << "none\n";	
}