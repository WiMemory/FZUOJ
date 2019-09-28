#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 140010;

struct stone {
	int x, y;
}stone[N];
bool cmpX(struct stone a, struct stone b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool cmpY(struct stone a, struct stone b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
int main() {
	int t, i, j, n, m, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		//若没有石头
		if (!k) {
			int ans = 0;
			if (m >= 2)ans += n;
			if (n >= 2)ans += m;
			printf("%d\n", ans); continue;
		}
		for (i = 0; i < k; i++) {
			scanf("%d%d", &stone[i].x, &stone[i].y);
		}
		//按行排序
		sort(stone, stone + k, cmpX);
		int ans = 0;
		int tx = 1, ty = 0;
		for (i = 0; i < k; i++) {
			if (tx == stone[i].x) {
				if (stone[i].y - ty > 2) ans++;
				ty = stone[i].y;
			}
			else {
				if (m >= 2) ans += stone[i].x - tx - 1;
				if (m + 1 - ty > 2) ans++;
				if (stone[i].y > 2) ans++;
				tx = stone[i].x;
				ty = stone[i].y;
			}
			if (i == k - 1) {
				if (m >= 2) ans += n - stone[i].x;
				if (m + 1 - stone[i].y > 2) ans++;
			}
		}
		//按列排序
		sort(stone, stone + k, cmpY);
		tx = 0;
		ty = 1;
		for (i = 0; i < k; i++) {
			if (ty == stone[i].y) {
				if (stone[i].x - tx > 2) ans++;
				tx = stone[i].x;
			}
			else {
				if (n >= 2) ans += stone[i].y - ty - 1;
				if (n + 1 - tx > 2) ans++;
				if (stone[i].x > 2) ans++;
				tx = stone[i].x;
				ty = stone[i].y;
			}
			if (i == k - 1) {
				if (n >= 2) ans += m - stone[i].y;
				if (n + 1 - stone[i].x > 2) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}