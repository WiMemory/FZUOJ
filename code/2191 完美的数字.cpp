#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
int main() {
	ll a, b, ans;
	ll up, down;
	ll i;
	while (cin >> a >> b) {
		ans = 0;
		--a;//减去1 - （a-1）的完美度
		up = pow(b, 0.333333333333);
		down = pow(a, 0.333333333333);
		for (i = 1; i <= up; i++) {
			ans += b / (i*i) - i + 1;
		}
		for (i = 1; i <= down; i++) {
			ans -= a / (i*i) - i + 1;
		}
		cout << ans << endl;
	}
}