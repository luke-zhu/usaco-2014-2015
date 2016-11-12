/*
ID: lukezhu1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

vector < int > breadth_first_search(vector < int >);

int v, vitamins[26], g, feeds[16][26];
deque < vector < int > > queue;

int main() {
	ofstream fout("holstein.out");
	ifstream fin("holstein.in");
	
	fin >> v;
	for (int i = 1; i <= v; ++i) {
		fin >> vitamins[i];
	}
	fin >> g;
	for (int i = 1; i <= g; ++i) {
		for (int j = 1; j <= v; ++j) {
			fin >> feeds[i][j];
		}
	}

	for (int i = 1; i <= g; ++i) {
		vector < int > set;
		set.push_back(i);
		queue.push_back(set);
	}
	vector < int > final_set;
	final_set = breadth_first_search(queue[0]);
	fout << final_set.size();
	for (int i = 0; i < final_set.size(); ++i) {
		fout << " " << final_set[i];
	}
	fout << "\n";
}

vector < int > breadth_first_search(vector < int > ordered_set) {
	queue.pop_front();
	bool meet;
	meet = true;
	for (int i = 1; i <= 25; ++i) {
		int sum_vitamins;
		sum_vitamins = 0;
		for (int j = 0; j < ordered_set.size(); ++j) {
			sum_vitamins += feeds[ordered_set[j]][i];
		}
		if (sum_vitamins < vitamins[i]) {
			meet = false;
		}
	}
	if (meet) {
		return ordered_set;
	}
	for (int i = ordered_set.back() + 1; i <= g; ++i) {
		vector < int > new_ordered_set;
		new_ordered_set = ordered_set;
		new_ordered_set.push_back(i);
		queue.push_back(new_ordered_set);
	}
	return breadth_first_search(queue[0]);
}