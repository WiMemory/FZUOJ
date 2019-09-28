#include<iostream>
using namespace std;
int main() {
	int C, M, N;
	cin >> C;
	while (C--) {
		cin >> M >> N;
		if (M == 1 || N == 1) cout << "No" << endl;
		else if (M % 2 == 0 || N % 2 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}