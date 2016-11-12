#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool milked[10000];
pair <int, int> cow[10000] ;

int main() {
	ofstream fout("msched.out");
	ifstream fin("msched.in");

	int n;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> cow[i].first >> cow[i].second;
	}
	sort(cow, cow + n);
	int milk;
	milk = 0;
	for (int i = n - 1; i >= 0; --i) {
		//cout << milk << "\n";
		for (int j = cow[i].second; j > 0; --j) {
			if (!milked[j]) {
				milked[j] = 1;
				milk += cow[i].first;
				break;
			}
		}
	}
	fout << milk << "\n";
}