#include<iostream>
int main() {
	int n, a, b, c, ans ;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		while (n--) {
			scanf("%d %d %d", &a, &b, &c);
			if (a < 60 || b < 60 || c < 60) continue;
			if ((a + b + c - 150.0) / 30.0 >= 3.0) ans++;
		}
		printf("%d\n", ans);
	}
}