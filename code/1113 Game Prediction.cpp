#include<iostream>
#include<algorithm>
using namespace std;
int N[50];
int ans, p;
bool mysort(int a, int b) {
	return a > b ? true : false;
}
void init() {
	p = ans = 0;
}
int main() {
	int m, n, i, x = 0, j;
	while (scanf("%d%d", &m, &n) != EOF && m != 0) {
		init();
		for (i = 0; i < n; i++) {
			scanf("%d", &N[i]);
		}
		getchar();
		printf("Case %d: ", ++x);
		sort(N, N + n, mysort);
		for (i = 0; i < n;) {
			for (j = n * m; j > 0; j--) {
				if (p > n - i) {
					break;
				}
				if (j > N[i]) {
					++p;
				}
				else if (j == N[i]) {
					if (p) {
						--p; ++i;
					}
					else {
						++ans; ++i;
					}
				}
			}
			if (p > n - i) {
				break;
			}
		}
		printf("%d\n", ans);
	}
}