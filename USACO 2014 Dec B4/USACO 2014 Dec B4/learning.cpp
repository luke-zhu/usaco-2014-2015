#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

pair <int, int> weight[50000];
int range[50000][2];

int main() {
	ofstream fout("learning.out");
	ifstream fin("learning.in");

	int n, a, b;
	fin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		char c;
		fin >> c;
		if (c == 'S') {
			fin >> weight[i].first;
		}
		else {
			fin >> c;
			fin >> weight[i].first;
			weight[i].second = 1;
		}
	}
	sort(weight, weight + n);

	for (int i = 1; i < n; ++i) {
		// spotted overides unspotted
		if (weight[i].first == weight[i - 1].first && weight[i].second != weight[i - 1].second) {
			weight[i].second = 0;
		}
		// both spotted
		else if (!weight[i].second && !weight[i - 1].second) {
			range[i][1] = weight[i].first;
			range[i][0] = weight[i - 1].first;
		}
		// heavier spotted
		else if (!weight[i].second && weight[i - 1].second) {
			range[i][1] = weight[i].first;
			if ((weight[i].first + weight[i - 1].first) % 2) {
				range[i][0] = (weight[i].first + weight[i - 1].first) / 2 + 1;
			}
			else {
				range[i][0] = (weight[i].first + weight[i - 1].first) / 2;
			}
		}
		// lower spotted
		else if (weight[i].second && !weight[i - 1].second) {
			range[i][0] = weight[i - 1].first;
			range[i][1] = (weight[i].first + weight[i - 1].first) / 2 + 1;
		}
	}

	for (int i = 1; i < n; ++i) {
		cout << range[i][0] << " " << range[i][1] << "\n";
	}

	int count;
	count = 0;
	for (int i = 1; i < n; ++i) {
		if (range[i][0] >= a && range[i][1] <= b) {
			count += range[i][1] - range[i][0];
		}
		else if (range[i][0] < a && range[i][1] > b) {
			count += b - a;
		}
		else if (range[i][0] < a && range[i][1] >= a) {
			count += range[i][1] - a;
		}
		else if (range[i][0] <= b && range[i][1] > b) {
			count += b - range[i][0] + 1;
		}
	}
	if (range[1][0] > a && !weight[0].second) {
		count += weight[0].first - a;
	}
	if (range[n - 1][1] <= b && !weight[n - 1].second) {
		count += b - weight[n - 1].first + 1;
	}
	cout << count << "\n";
	fout << count << "\n";
}