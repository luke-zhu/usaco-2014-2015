#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fout("delivery.out");
	ifstream fin("delivery.in");

	int n;
	fin >> n;
	int coord[100][2];
	for (int i = 0; i < n; ++i) {
		fin >> coord[i][0];
		fin >> coord[i][1];
	}
	
	int max_distance;

	for (int i = 0; i < n; ++i) {
		
	}
}