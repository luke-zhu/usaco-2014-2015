#include <iostream>
#include <fstream>
#include <queue>
#include <functional>
#include <map>

using namespace std;

typedef pair<int, int> ii;

int a, b, n, cost[1000], route[1001][1001][3], source[1001][2], num_changes;
long long dist[1001];

map<int, int> routes[1000];

int main() {
	ofstream fout("cowroute.out");
	ifstream fin("cowroute.in");

	fin >> a >> b >> n;
	for (int i = 0; i < n; ++i) {
		int num_cities;
		fin >> cost[i] >> num_cities;
		for (int j = 0; j < num_cities; ++j) {
			int city;
			fin >> city;
			routes[i][city] = j;
		}
		for (map<int, int>::iterator it = routes[i].begin(); it != routes[i].end(); ++it) {
			for (map<int, int>::iterator it2 = ++it; it2 != routes[i].end(); ++it2) {
				if (cost[i] < route[it->first][it2->first][0]) {
					route[it->first][it2->first][0] = cost[i];
					route[it->first][it2->first][1] = it2->second - it->second;
					route[it->first][it2->first][2] = i;
				}
			}
		}
	}

	for (int i = 1; i <= 1000; ++i) {
		dist[i] = 100000000000;
	}
	dist[a] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, a));
	while (!pq.empty()) {
		ii top = pq.top();
		//cout << top.second << " " << top.first << "\n";
		pq.pop();
		int v, d;
		v = top.second;
		d = top.first;
		if (d == dist[v]) {
			for (int i = 0; i <= 1000; ++i) {
				if (dist[i] > dist[v] + route[v][i][0]) {
					//cout << nxt << " " << dist[nxt] << "\n";
					dist[i] = dist[v] + route[v][i][0];
					pq.push(ii(dist[i], i));
					source[i][0] = v;
					source[i][1] = route[v][i][2];
				}
			}
		}
	}
	
	if (source[b][0] == 0) {
		fout << -1 << " " << -1 << "\n";
	}
	int x = b;
	while (x != a) {
		num_changes += routes[source[x][1]][x] - routes[source[x][1]][source[x][0]];
		x = source[x][0];
	}
	//cout << dist[b] << " " << num_changes << "\n";
	fout << dist[b] << " " << num_changes << "\n";
}