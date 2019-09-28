#include<iostream>
int main() {
	int n, a, ans;
	while (scanf("%d", &n) != EOF) {
		a = 2;
		ans = 1;
		while (a != 1) {
			if (a <= n) {
				a *= 2;
				ans++;
			}
			else if (a > n&&a <= 2*n) {
				a = (a - n) * 2 - 1;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}