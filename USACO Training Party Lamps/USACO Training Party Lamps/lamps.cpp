/*
ID: lukezhu1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <set>

using namespace std;

void do_b1(vector<int> &v) {
	for (int i = 0; i<(int)v.size(); ++i) {
		v[i] = 1 - v[i];
	}
}
void do_b2(vector<int> &v) {
	for (int i = 0; i<(int)v.size(); i += 2) {
		v[i] = 1 - v[i];
	}
}
void do_b3(vector<int> &v) {
	for (int i = 1; i<(int)v.size(); i += 2) {
		v[i] = 1 - v[i];
	}
}
void do_b4(vector<int> &v) {
	for (int i = 0; 3 * i<(int)v.size(); ++i) {
		v[3 * i] = 1 - v[3 * i];
	}
}
bool matches(const vector<int> &a, const vector<int> &b) {
	for (int i = 0; i<(int)a.size(); ++i) {
		if (b[i] != -1 && a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	ifstream fin("lamps.in");
	int N, C;
	fin >> N >> C;
	vector<int> final_state(N, -1);
	int x;
	int set_to = 1;
	while (fin >> x) {
		if (x == -1) {
			set_to = 0;
		}
		else {
			final_state[x - 1] = set_to;
		}
	}
	fin.close();

	vector<int> start_state(N, 1);
	set< vector<int> > sols;
	for (int b1 = 0; b1<2; ++b1) {
		if (b1 > C) {
			break;
		}
		for (int b2 = 0; b2<2; ++b2) {
			if (b1 + b2 > C) {
				break;
			}
			for (int b3 = 0; b3<2; ++b3) {
				if (b1 + b2 + b3 > C) {
					break;
				}
				int b4 = (C - b1 - b2 - b3) & 1;
				vector<int> cur = start_state;
				if (b1) {
					do_b1(cur);
				}
				if (b2) {
					do_b2(cur);
				}
				if (b3) {
					do_b3(cur);
				}
				if (b4) {
					do_b4(cur);
				}
				if (matches(cur, final_state)) {
					sols.insert(cur);
				}
			}
		}
	}

	ofstream fout("lamps.out");
	if (sols.size() == 0) {
		fout << "IMPOSSIBLE\n";
	}
	else {
		for (set< vector<int> >::const_iterator it = sols.begin(); it != sols.end(); ++it) {
			for (int i = 0; i<N; ++i) {
				fout << it->operator[](i);
			}
			fout << '\n';
		}
	}
	fout.close();

	return 0;
}
/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string final_config, config[9];

bool config_cmp(string s, string fin) {
for (int i = 0;  i < s.length(); ++i) {
if (fin[i] != '2' && fin[i] != s[i]) {
return false;
}
}
return true;
}

int main() {

	ofstream fout("lamps.out");
	ifstream fin("lamps.in");

	int n, c;
	fin >> n >> c;
	final_config.insert(0, n, '2');
	int x;
	fin >> x;
	while (x != -1) {
		final_config[x - 1] = '1';
		fin >> x;
	}
	fin >> x;
	while (x != -1) {
		final_config[x - 1] = '0';
		fin >> x;
	}
	config[1].insert(0, n, '1'); // all 2 
	config[2].insert(0, n, '0'); // none 1
	//cout << "clear 1, 2\n";
	config[3] = config[1]; // odd 1
	config[4] = config[2]; // even 1
	for (int i = 0; i < config[1].length(); ++i) {
		if (i % 2) {
			config[3][i] = '0';
			config[4][i] = '1';
		}
	}
	//cout << "clear 3, 4\n";
	config[5] = config[1]; // 3k-off 1, 3
	for (int i = 0; i < config[1].length(); ++i) {
		if (i % 3 == 0) {
			config[5][i] = '0';
		}
	}
	config[6] = config[2]; // 3k-on 2 
	for (int i = 0; i < config[1].length(); ++i) {
		if (i % 3 == 0) {
			config[6][i] = '1';
		}
	}
	config[7] = config[5]; // 3k-off + even 2
	config[8] = config[5]; // 3k-off + odd 2
	for (int i = 0; i < config[1].length(); ++i) {
		if (i % 2 == 0) {
			if (config[7][i] == '0') {
				config[7][i] = '1';
			}
			else {
				config[7][i] = '0';
			}
		}
		else {
			if (config[8][i] == '0') {
				config[8][i] = '1';
			}
			else {
				config[8][i] = '0';
			}
		}
	}
	bool not_impossible;
	not_impossible = false;
	for (int i = 1; i <= 8; ++i) {
		if (config_cmp(config[i], final_config)) {
			//cout << "pass " << config[i] << "\n";
			if (c == 0 && i != 1) {
				continue;
			}
			else if (c == 1 && i == 1 || i >= 6) {
				continue;
			}
			else if (c == 2 && i == 5) {
				continue;
			}
			else {
				fout << config[i] << "\n";
				not_impossible = true;
			}
		}
		else { 
			//cout << "fail " << config[i] << "\n"; 
		}
	}
	if (!not_impossible) {
		fout << "IMPOSSIBLE\n";
	}
}*/