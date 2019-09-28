#include<iostream>

int main() {
	double length;
	double goal[279];
	goal[0] = 0.00f;
	int i;
	//将所有可能情况存入数组goal
	for (i = 1; i < 278; i++) {
		goal[i] = goal[i - 1] + 1 / (float)(i + 1);
	}
	while (scanf("%lf", &length) != EOF) {
		if (length == 0.00) {
			break;
		}
		for (i = 1; i <= 278; i++) {
			if (length <= goal[i]) {
				printf("%d card(s)\n", i);
				break;
			}
		}
	}
}