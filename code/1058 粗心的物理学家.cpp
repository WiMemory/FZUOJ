#include<iostream>

int main() {
	int n, i;
	while (scanf("%d", &n) != EOF) {
		double ans = 0;
		for (i = n; i > 0; i--) {
			ans += 1.0 / i;
		}
		printf("%.12lf\n", ans);
	}
}