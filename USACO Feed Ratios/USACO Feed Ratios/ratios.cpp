/*
ID: lukezhu1
PROG: ratios
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int target[3];
int feed[3][3];

int main()
{
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");
	for (int i = 0; i < 3; ++i)
		fin >> target[i];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			fin >> feed[i][j];

	bool flag = false;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			for (int k = 0; k < 100; ++k)
			{
				if (i == 0 && j == 0 && k == 0)
					continue;
				int a = feed[0][0] * i + feed[1][0] * j + feed[2][0] * k;
				int b = feed[0][1] * i + feed[1][1] * j + feed[2][1] * k;
				int c = feed[0][2] * i + feed[1][2] * j + feed[2][2] * k;

				if (a * target[1] == b * target[0] && b * target[2] == c * target[1] && a / target[0] > 0)
				{
					fout << i << " " << j << " " << k << " " << a / target[0] << "\n";
					flag = true;
				}
				if (flag) {
					return 0;
				}
			}
		}
	}

	fout << "NONE\n";
	return 0;
}