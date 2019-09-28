#include<iostream>
using namespace std;
int main() {
	int n, k, ans, t;
	while (scanf("%d%d", &n, &k) != EOF) {
		ans = n;
		while (n >= k) {
			t = n / k;
			ans += n / k;
			n %= k;
			n += t;
		}
		cout << ans << endl;
	}
}