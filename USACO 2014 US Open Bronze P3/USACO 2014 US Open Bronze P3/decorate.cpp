#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector < int > graphs[50000];

void create_graph(int key, int i) {
	graphs[i].push_back(key);
	create_graph(int )
}

int main() {
	ofstream fout("decorate.out");
	ifstream fin("decorate.in");

	int n, m;
	map < int, int > paths;
	vector < int > graphs[50000];

	for (int i = 0; i < m; ++i) {
		int a, b;
		fin >> a >> b;
		if (paths.count(a)) {
			paths[b] = a;
		} 
		else {
			paths[a] = b;
		}
	}
	int i = 0;
	int a = 0;
	while (paths.size()) {
		create_graph(paths.begin(), i)
	}

}