#include<iostream>
char m[12][12];
int turn[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int ans, num;
void DFS(int i, int j, char c) {
	int k;
	if (m[i][j] != c) {
		return;
	}
	else {
		++num;
		m[i][j] = '.';
		for (k = 0; k < 4; k++) {
			DFS(i + turn[k][0], j + turn[k][1], c);
		}
	}
}
int main() {
	int T, W, H, i, j;
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		memset(m, '.', sizeof(m));
		scanf("%d%d", &W, &H);
		for (i = 1; i <= H; i++) {
			scanf("%s", m[i]);
		}
		for (i = 1; i <= H; i++) {
			for (j = 1; j <= W; j++) {
				if (m[i][j] == '.') {
					continue;
				}
				else {
					num = 0;
					DFS(i, j, m[i][j]);
					if (num > ans) {
						ans = num;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}