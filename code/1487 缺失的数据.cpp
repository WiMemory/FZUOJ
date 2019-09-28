#include<iostream>
long long ans;
int main() {
	int n, i, num;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		for (i = 1; i <= n-1; i++) {
			ans += i;
			scanf("%d", &num);
			ans -= num;
		}
		ans += n;
		printf("%I64d\n", ans);
	}
}