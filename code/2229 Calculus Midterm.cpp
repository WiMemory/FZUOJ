#include<iostream>
int main() {
	int x, y, z, ans;
	while (scanf("%d%d%d", &x, &y, &z) != EOF) {
		ans = x * 3 + y * 2 + z * 6;
		if (ans >= 60) {
			printf("I passed the exam.\n");
		}
		else {
			printf("Exam was too hard.\n");
		}
		printf("%d\n", ans);
	}
	return 0;
}