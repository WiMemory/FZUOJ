#include<iostream>
int num[105];
int main() {
	int T;
	int n, m, a, b;
	int i;
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			if (a > 0) {
				num[b - 1] *= 2;
			}
			else if (a < 0) {
				num[b - 1] += 2;
			}
		}
		for (i = 0; i < n; i++) {
			if (num[i] > ans) {
				ans = num[i];
			}
		}
		printf("%d\n", ans);
	}
}