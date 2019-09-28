#include<iostream>
int main() {
	int n, i, num, sum1, sum0;
	while (scanf("%d", &n) != EOF) {
		sum0 = 0;
		sum1 = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &num);
			sum1 += num;
			sum0 += i + 1;
		}
		sum0 -= i;
		printf("%d\n", sum1 - sum0);
	}
}