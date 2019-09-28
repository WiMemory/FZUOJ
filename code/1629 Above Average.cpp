#include<iostream>
int num[1005];
int main() {
	int C, N, i;
	double aver, ans;
	scanf("%d", &C);
	while (C--) {
		ans = aver = 0;
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%d", &num[i]);
			aver += num[i];
		}
		aver /= (double)N;
		for (i = 0; i < N; i++) {
			if (num[i] > aver) {
				++ans;
			}
		}
		ans /= (double)N;
		ans *= 100;
		printf("%.3lf%%\n", ans);
	}
}