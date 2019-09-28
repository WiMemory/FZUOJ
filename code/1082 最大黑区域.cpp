#include<iostream>
int n, m, num;
int chart[100][100];
void bfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || chart[i][j] == 0) {
		return;
	}
	chart[i][j] = 0;
	++num;
	bfs(i - 1, j);
	bfs(i, j + 1);
	bfs(i + 1, j);
	bfs(i, j - 1);
}
int main() {
	int i, j, ans;
	while (scanf("%d %d", &n, &m) != EOF && n != 0) {
		ans = 0;
		memset(chart, 0, sizeof(chart));
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &chart[i][j]);
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (chart[i][j] == 1) {
					num = 0;
					bfs(i, j);
					if (num > ans) {
						ans = num;
					}
				}
			}
		}
		printf("%d\n", ans);
		//ÎüÊÕ¿ÕĞĞ
		getchar();
		getchar();
	}
	return 0;
}