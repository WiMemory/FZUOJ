#include<iostream>
int a[20];
int main() {
	int n, t = 0, i, j, k, p, q, r;
	while (scanf("%d", &n) != EOF && n != 0) {
		if (t > 0) {
			printf("\n");
		}
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (i = 1; i <= n - 5; i++)
			for (j = i + 1; j <= n - 4; j++)
				for (k = j + 1; k <= n - 3; k++)
					for (p = k + 1; p <= n - 2; p++)
						for (q = p + 1; q <= n - 1; q++)
							for (r = q + 1; r <= n; r++)
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[k], a[p], a[q], a[r]);
		++t;
	}
	return 0;
}