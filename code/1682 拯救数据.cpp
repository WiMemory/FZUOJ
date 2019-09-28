#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef __int64 ll;
string s;
ll str2int() {
	ll N = 0;
	int o = 1;
	for (int i = s.length()-1; i >= 0; i--) {
		N += (s[i] - '0')*o;
		o *= 10;
	}
	return N;
}
int main() {
	ll N, ans;
	double o;
	int ge, len, i, po;
	while (cin>>s) {
		len = s.length();
		ans = 0;
		o = pow(0.8, len - 1);
		N = str2int();
		for (i = 0; i < len; i++) {
			po = pow(10.0, len - i - 1);
			ge = N / po;
			ge %= 10;
			if (ge < 3) {
				ans += ge * o * po;
			}
			else if (ge == 3) {
				ans += ge * o * po;
				--ans;
				break;
			}
			else if (ge < 6) {
				--ge;
				ans += ge * o * po;
			}
			else if (ge == 6) {
				--ge;
				ans += ge * o * po;
				--ans;
				break;
			}
			else {
				ge -= 2;
				ans += ge * o * po;
			}
			o /= 0.8;
		}
		printf("%I64d\n", ans);
	}
}