#include<iostream>
#define ll long long
int main() {
	int A, B;
	ll ans;
	while (scanf("%d%d", &A, &B) != EOF) {
		ans = (ll)((A + 1)*A / 2) * (ll)((B + 1)*B / 2);
		printf("%I64d\n", ans);
	}
}