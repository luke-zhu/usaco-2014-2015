#include <iostream>

using namespace std;

int main() {
	double c ,n;
	cin >> n;
	c = n;
	int i = 1;
	while (n != 0) {
		cout << "b" << i << " = " << n << "\n";
		n = c - 1 / n;
		++i;
	}
	cout << n << "\n";
}