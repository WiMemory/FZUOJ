#include<iostream>
int main() {
	int T, ans, i = 0;
	scanf("%d", &T);
	__int64 A, B;
	while (T--) {
		++i;
		scanf("%I64d %I64d", &A, &B);
		ans = 0;
		while (A > B) {
			A = A - (A % ((A / 2) + 1));
			++ans;
		}
		printf("Case %d: %d\n", i, ans);
	}
}