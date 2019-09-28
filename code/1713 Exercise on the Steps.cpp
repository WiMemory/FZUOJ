#include<iostream>
int main() {
	int A, B;
	int p, ans;
	while (scanf("%d%d", &A, &B) != EOF) {
		p = ans = A;
		while (p%B != 0) {
			if (p > B) {
				p -= B;
			}
			else {
				p += A;
				if (p > ans) {
					ans = p;
				}
			}
		}
		printf("%d\n", ans);
	}
}