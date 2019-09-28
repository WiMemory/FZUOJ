#include<iostream>
int main() {
	int T, n, ans, num;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = 0;
		while (n != 0) {
			num = n % 10;
			n /= 10;
			if (num == 0 || num == 4 || num == 6 || num == 9) {
				++ans;
			}
			else if (num == 8) {
				ans += 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}