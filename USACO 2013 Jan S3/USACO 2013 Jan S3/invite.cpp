#include <iostream>
#include <fstream>

using namespace std;

int sum_g, group[250000], i, g_size[250000][2];

int main() {
	ofstream fout("invite.out");
	ifstream fin("invite.in");

	int	n, g;
	fin >> n >> g;
	for (int i = 0; i < g; ++i) {
		g_size[i][0] = sum_g;
		fin >> g_size[i][1];
		g_size[i][1] += sum_g;
		sum_g = g_size[i][1];
		for (int j = g_size[i][0]; j < g_size[i][1]; ++j) {
			fin >> group[j];
		}
	}
	
	for (int i = 0; i < g; ++i) {
		cout << g_size[i][1] - g_size[i][0] << " ";
		for (int j = g_size[i][0]; j < g_size[i][1]; ++j) {
			cout << group[j] << " ";
		}
		cout << "\n";
	}

	int num_cows;
	num_cows = 1;
}