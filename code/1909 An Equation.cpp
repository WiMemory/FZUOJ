#include<iostream>
int num[4];
int main() {
	int T, n, i;
	n = 1;
	bool flag;
	scanf("%d", &T);
	while (n <= T) {
		for (i = 0; i < 4; i++) {
			scanf("%d", &num[i]);
		}
		flag = false;
		if (num[0] + num[1] == num[2] + num[3] || num[0] + num[2] == num[1] + num[3] || num[0] + num[3] == num[1] + num[2]) {
			flag = true;
		}
		printf("Case %d: %s\n", n, flag ? "Yes" : "No");
		++n;
	}
}