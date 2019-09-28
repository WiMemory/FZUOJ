#include<iostream>
int main() {
	int T, i, j, x = 0;
	int N, M;
	scanf("%d", &T);
	char c;
	bool winner;
	while (T--) {
		winner = true;
		++x;
		scanf("%d %d", &N, &M);
		getchar();
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				c = getchar();
				if (c == 'O') {
					winner = !winner;
				}
			}
			getchar();
		}
		printf("Case %d: ", x);
		if (!winner) {
			printf("Maze\n");
		}
		else printf("Fat brother\n");
	}
}