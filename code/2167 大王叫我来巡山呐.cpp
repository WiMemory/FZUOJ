#include<iostream>
int main() {
	int N, ans, a, b;
	while (scanf("%d", &N) != EOF) {
		a = N / 7;
		ans = a * 2;
		b = N % 7;
		if (b == 6) {
			++ans;
		}
		printf("%d\n", ans);
	}
}