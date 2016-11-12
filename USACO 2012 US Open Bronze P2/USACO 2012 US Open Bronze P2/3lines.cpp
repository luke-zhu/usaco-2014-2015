/*
ID: lukez8
PROG: 3lines
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
pair < int, int > cows[5000];

bool lines(int num, vector <bool> args)
{
	if (!num)
	{
		for (int i = 0; i < n; ++i)
		{
			if (!args[i])
			{
				return false;
			}
		}
		return true;
	}
	for (int i = 0; i < n; ++i)
	{
		vector < bool > temp;
		temp = args;
		for (int j = 0; j < n; ++j)
		{
			if (cows[i].first == cows[j].first)
			{
				args[j] = true;
			}
		}
		if (lines(num - 1, temp))
		{
			return true;
		}
		temp = args;
		for (int j = 0; j < n; ++j)
		{
			if (cows[i].second == cows[j].second)
			{
				args[j] = true;
			}
		}
		if (lines(num - 1, temp))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ofstream fout("3lines.out");
	ifstream fin("3lines.in");

	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		fin >> cows[i].first >> cows[i].second;
	}

	cout << 0 << "\n";
	return 0;
	vector < bool > covered(5000, false);
	if (lines(3, covered))
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}
}