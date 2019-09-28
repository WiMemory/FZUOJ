#define gets(x) gets_s(x)

#include<iostream>
#include<cstring>
char A[110];
char B[55];
int len;
bool isre(void) {
	for (int i = 0; i < len / 2; i++) {
		if (A[i] != A[len - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	int T, n = 1, ans, i, j, Alen, Blen;
	scanf("%d", &T);
	getchar();
	char index;
	while (n <= T) {
		ans = 0;
		gets(A);
		gets(B);
		Alen = strlen(A);
		Blen = strlen(B);
		len = Alen + Blen;
		for (i = Alen, j = 0; i < len; i++, j++) {
			A[i] = B[j];
		}
		if (isre()) {
			++ans;
		}
		for (i = Alen - 1; i >= 0; i--) {
			index = A[i];
			for (j = i; j < i + Blen; j++) {
				A[j] = A[j + 1];
			}
			A[j] = index;
			if (isre()) {
				++ans;
			}
		}
		printf("Case %d: %d\n", n, ans);
		++n;
	}
}