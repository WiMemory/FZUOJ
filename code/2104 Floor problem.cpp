#include<iostream>
int main() {
	int T, n, L, R, ans, i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &L, &R);
		ans = 0;
		for (i = L; i <= R; i++) {
			ans += n / i;
		}
		printf("%d\n", ans);
	}
}