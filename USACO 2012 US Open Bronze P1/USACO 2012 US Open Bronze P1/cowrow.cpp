/*
ID: lukez8
PROG: cowrow
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ofstream fout("cowrow.out");
	ifstream fin("cowrow.in");
	int line[1000];

	int n;
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		fin >> line[i];
	}
	int max_count;
	max_count = 0;
	for (int i = 0; i < n; ++i)
	{
		int k, reduced[1000];
		k = 0;
		for (int j = 0; j < n; ++j)
		{
			if (line[i] != line[j])
			{
				reduced[k] = line[j];
				++k;
			}
		}
		int last, count;
		last = 0;
		count = 0;
		for (int j = 0; j < k; j++)
		{
			if (reduced[j] == last)
			{
				++count;
			}
			else
			{
				max_count = max(max_count, count);
				last = reduced[j];
				count = 1;
			}
		}
		max_count = max(max_count, count);
	}
	cout << max_count << "\n";
}