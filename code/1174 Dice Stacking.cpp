#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10010;
int h[N][6], id[N][7], a[7] = { 5,3,4,1,2,0 }, judge[7];
int main() {
	int t, n, i, j, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			for (j = 0; j < 6; j++) {
				scanf("%d", &h[i][j]);
				id[i][h[i][j]] = j;
			}
		}
		int ans = 0;
		for (i = 0; i < 6; i++) {
			memset(judge, 0, sizeof(judge));
			int num = 0;
			int tnum1 = h[1][i];
			int tnum2 = h[1][a[i]];
			judge[tnum1] = 1;
			judge[tnum2] = 1;
			for (j = 6; j > 0; j--) {
				if (!judge[j]) {
					num += j;
					break;
				}
			}
			for (j = 2; j <= n; j++) {
				int tid = id[j][tnum2];
				tnum1 = tnum2;
				tnum2 = h[j][a[tid]];
				memset(judge, 0, sizeof(judge));
				judge[tnum1] = 1;
				judge[tnum2] = 1;
				for (k = 6; k > 0; k--) {
					if (!judge[k]) {
						num += k; break;
					}
				}
			}
			if (num > ans)ans = num;
		}
		printf("%d\n", ans);
	}
	return 0;
}