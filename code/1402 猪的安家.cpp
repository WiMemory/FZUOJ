#include<iostream>
typedef long long ll;

int main() {
	int n, i, flag, j;
	ll sum, times;
	ll a[10][2];
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%I64d%I64d", &a[i][0], &a[i][1]);
		}
		times = a[0][0];
		sum = a[0][1];
		for (i = 1; i < n; i++) {
			while (sum%a[i][0] != a[i][1]) {
				sum += times;
			}
			times *= a[i][0];
		}
		printf("%I64d\n", sum);
	}
}