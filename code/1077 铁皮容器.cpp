#include<iostream>
#define pi 3.14159265358

int main() {
	int k, flag;
	double v, r;
	scanf("%d", &k);
	while (k--) {
		scanf("%lf", &v);
		flag = 0;
		for (r = 0.00;; r += 0.01) {
			if (pi*r*r > 500) {
				break;
			}
			else if ((500 * r - pi * r*r*r) > v) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			printf("%.1lf\n", r);
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}