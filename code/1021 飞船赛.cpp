#include<iostream>
int main() {
	int N, x, i, s, ans;
	int speed[101] = { 0 };
	while (scanf("%d", &N) != EOF && N != 0) {
		ans = 0;
		for (i = 0; i < N; i++) {
			scanf("%d %d", &x, &s);
			++speed[s];
			for (++s ; s < 101; s++) {
				ans += speed[s];
				ans %= 1000000;
			}
		}
		printf("%d\n", ans);
		memset(speed, 0, sizeof(speed));
	}
}