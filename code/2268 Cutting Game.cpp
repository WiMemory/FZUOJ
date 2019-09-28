#include <stdio.h>
int main() {
	int t, k = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i < 31; i++) {
			if (1 << i >= n) {
				printf("Case %d: %d\n", k++, i);
				break;
			}
		}
	}
	return 0;
}