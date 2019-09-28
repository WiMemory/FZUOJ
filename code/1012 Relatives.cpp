#include<iostream>
#include<math.h>
using namespace std;
int ol(int x) {
	int i, ans = x;
	for (i = 2; i * i <= x; i++) {
		if (x%i == 0) {
			ans = ans - ans / i;
			while (x%i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		ans = ans - ans / x;
	}
	return ans;
}
int main() {
	int n, ans, i, j;
	while (scanf("%d", &n) != EOF && n != 0) {
		printf("%d\n", ol(n));
	}

	return 0;
}