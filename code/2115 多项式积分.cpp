#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int>tp;

tp a[11];
int t, n;

bool cmp(tp a, tp b) {
	return a.second > b.second;
}

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i].first);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i].second);
		sort(a, a + n, cmp);
		int flag = 0;
		for (int i = 0; i < n; i++) {
			int up = a[i].first;
			int low = a[i].second + 1;
			if (up == 0)
				continue;
			if (up > 0 && flag)
				printf("+");
			flag = 1;
			if (up < 0) {
				printf("-");
				up = -up;
			}
			int g = gcd(low, up);
			if (up / g > 1 || low > g)
				printf("%d", up / g);
			if (low > g)
				printf("/%d", low / g);
			printf("x");
			if (low > 1)
				printf("^%d", low);
		}
		printf("\n");
	}
	return 0;
}