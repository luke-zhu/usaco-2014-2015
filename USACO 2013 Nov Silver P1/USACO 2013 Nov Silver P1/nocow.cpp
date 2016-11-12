#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
	ofstream fout("nocow.out");
	ifstream fin("nowcow.in");

	int n, k;
	fin >> n >> k;

	string words[100][35];
	int num_words;
	//Get array of adjs
	for (int i = 0; i < n; ++i) {
		num_words = 0;
		while (words[i][num_words - 1] != "cows.") {
			fin >> words[i][num_words];
			++num_words;
		}
	}
	map < string, int > adjs;
	//Get key of distinct adjs
	for (int i = 0; i < num_words; ++j) {
		for (int i = 0; i < n; ++i)
		{
			adjs[	
		}
	}
}