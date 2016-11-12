#include <iostream>
#include <fstream>
#include <array>
#include <vector>

using namespace std;

array < int, 4 > teams = { 0, 0, 0, 0 };

void set_teams(vector < int > levels, int team) {
	int diff;
	for (int i = 0; i < 10; ++i) {
		teams[team] += levels[i];
		for (int j = i + 1; j < 11; ++j) {
			teams[team] += levels[j];
			for (int k = j + 1; k < 12; ++k) {
				teams[team] += levels[k];
				set_teams(vector < int >)
				diff = max(teams[i]
			}
		}
	}
}

int main() {
	ofstream fout("bteams.out");
	ifstream fin("bteams.in");
	vector < int > levels(12, 0);

	for (int i = 0; i < 12; ++i) {
		fin >> levels[i];
	}
	fin.close();

	for (int i = 0; i < 10; ++i) {
		for (int j = i + 1; j < 11; ++j) {
			for (int k = j + 1; k < 12; ++k) {
				for (int i = 0; i < 10; ++i) {
					levels.
					for (int j = i + 1; j < 11; ++j) {
						for (int k = j + 1; k < 12; ++k) {
						}
					}
				}
			}
		}
	}
}