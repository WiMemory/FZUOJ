#include<iostream>
int main() {
	int n, num[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };
	while (scanf("%d", &n) != EOF && n >= 0) {
		if (n == 0) {
			printf("NO\n");
			continue;
		}
		for (int i = 9; i >= 0; --i)
			if (n >= num[i])
				n -= num[i];
		printf("%s\n", (!n) ? "YES" : "NO");
	}
	return 0;
}