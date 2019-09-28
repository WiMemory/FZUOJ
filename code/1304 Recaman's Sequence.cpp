#include<iostream>
//int MAXN = 0;
int a[500001] = { 0 };
bool visit[3012501] = { 0 }; //a[k]的最大值为3012500
int main() {
	int i;
	for (i = 1; i <= 500000; i++) {
		if (a[i - 1] - i > 0 && !visit[a[i - 1] - i]) {
			a[i] = a[i - 1] - i;
		}
		else a[i] = a[i - 1] + i;
		visit[a[i]] = 1;
		//if (a[i] > MAXN) MAXN = a[i];
	}
	//printf("%d\n", MAXN);
	while (scanf("%d", &i) != EOF) {
		if (i < 0) break;
		printf("%d\n", a[i]);
	}
}