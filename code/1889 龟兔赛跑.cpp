#include<iostream>
int main() {
	int X, T, K, U, V;
	int s1, s2;
	scanf("%d", &X);
	while (X--) {
		scanf("%d %d %d %d", &T, &K, &U, &V);
		s1 = (T - K)*U;
		s2 = T * V;
		if (s1 == s2) {
			printf("-1\n");
		}
		else if (s1 > s2) {
			printf("0\n");
		}
		else printf("1\n");
	}
}