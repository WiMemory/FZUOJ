#include<iostream>
int P, T;//P¸öÈË£¬T¿ÃÊı
int o[100][100];
int equal(int i, int j) {
	int k;
	for (k = 1; k <= T; k++) {
		if (o[i][k] != o[j][k]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	while (scanf("%d%d", &P, &T) != EOF) {
		memset(o, 0, sizeof(o));
		int i, j;
		while (scanf("%d%d", &i, &j) && i != 0 && j != 0) {
			o[i][j] = 1;
		}
		int re = 1, cf;
		for (i = 2; i <= P; i++) {
			cf = 0;
			for (j = 1; j < i; j++) {
				if (equal(i, j)) {
					cf = 1;
					break;
				}
			}
			if (!cf) {
				++re;
			}
		}
		printf("%d\n", re);
	}
	return 0;
}