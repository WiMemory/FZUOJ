#include<iostream>
int main() {
	int x, y, k;
	while (scanf("%d %d %d", &x, &y, &k) != EOF) {
		if (x*y*k >= 100000) {
			printf("1\n");
		}
		else printf("0\n");
	}
}