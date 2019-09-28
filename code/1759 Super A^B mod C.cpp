#include<iostream>
typedef __int64 ll;
const int max = 1e6 + 10;
char B[max];
ll A, C;
//������
ll qsm(ll base, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1 != 0) {
			ans = ans * base%C;
		}
		base = base * base%C;
		n >>= 1;
	}
	return ans;
}
//ŷ������
ll ol(ll x) {
	ll i, ans = x;
	for (i = 2; i * i <= x; i++) {
		if (x%i == 0) {
			ans = ans - ans / i;
			while (x%i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		ans = ans - ans / x;
	}
	return ans;
}
int main() {
	ll i, b, ans, tmp;
	while (scanf("%I64d%s%I64d", &A, B, &C) != EOF)
	{
		ans = 0; b = 0; tmp = ol(C);
		ll len = strlen(B);
		//�ַ���λתΪ������ȡģ
		for (i = 0; i < len; i++)
			b = (b * 10 + B[i] - '0') % tmp;
		b += tmp;
		ans = qsm(A, b);
		printf("%I64d\n", ans);
	}
}