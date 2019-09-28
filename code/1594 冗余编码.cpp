#include<iostream>
using namespace std;
int o[100][15];
char str[16];
int main() {
	int n, m, i, j, sum, ans;
	while (scanf("%d%d", &n, &m) != EOF) {
		ans = 1;
		for (i = 0; i < n; i++) {
			cin >> str;
			for (j = 0; j < m; j++) {
				o[i][j] = str[j] - '0';
			}
		}
		for (i = 0; i < m; i++) {
			sum = 1;
			for (j = 0; j < n; j++) {
				if (!o[j][i]) ++sum;
			}
			if (ans < sum) ans = sum;
		}
		printf("%d\n", ans);
	}
}