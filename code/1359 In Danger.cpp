//POJ1781
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	char ch;
	int x, y, z, pos;
	double n;
	while (cin >> x >> ch >> z) {
		if (!x && !z) break;
		n = x * pow(10.0, z);
		pos = log(n) / log(2.0);
		n -= pow(2.0, pos);
		n = n * 2 + 1;
		cout << int(n) << endl;
	}
	return 0;
}