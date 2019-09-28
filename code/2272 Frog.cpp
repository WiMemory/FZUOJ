#include<iostream>
using namespace std;
int main() {
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cout << (m - 2 * n) / 2 << ' ' << n - (m - 2 * n) / 2 << endl;
	}
}