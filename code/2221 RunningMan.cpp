#include<iostream>
using namespace std;
int main() {
	int T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		if (M % 2 == 0) {
			printf("%s\n", N >= M / 2 * 3 - 1 ? "Yes" : "No");
		}
		else {
			printf("%s\n", N >= M / 2 * 3 ? "Yes" : "No");
		}
	}
	return 0;
}