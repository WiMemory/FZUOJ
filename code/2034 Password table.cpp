#include<iostream>
int tb[10][10];
char qu[7];
int main() {
	int T, n, m, q, t = 1;
	int i, j;
	int num;
	scanf("%d", &T);
	while (t <= T) {
		scanf("%d%d%d", &n, &m, &q);
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf("%d", &tb[i][j]);
			}
		}
		getchar();
		printf("Case %d:\n", t);
		for (i = 0; i < q; i++) {
			scanf("%s", qu);
			for (j = 0; j <= 4; j += 2) {
				num = tb[qu[j + 1] - '0'][qu[j] - 'A' + 1];
				if (!(num / 10)) {
					printf("0");
				}
				printf("%d", num);
			}
			printf("\n");
		}
		++t;
	}
}