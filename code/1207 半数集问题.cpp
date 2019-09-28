#include<iostream>
using namespace std;
int a[202] = { 0 };
int halfSet(int n) {
	if (a[n] == 0) {
		int sum = 1;
		for (int i = 1; i <= n / 2; ++i) {
			sum += halfSet(i);
			if (i > 9 && ((i / 10) <= (i % 10 / 2)))
				sum -= halfSet(i / 10);
		}
		a[n] = sum;

	}
	return a[n];
}
int main() {
	int n;
	while (cin >> n) {
		cout << halfSet(n) << endl;
	}
}