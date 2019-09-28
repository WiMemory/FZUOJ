#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.14159265358
int main() {
	double D, v;
	while (scanf("%lf%lf", &D, &v) != EOF && D != 0) {
		printf("%.3lf\n", cbrt(D*D*D - 6 * v / pi));
	}
	return 0;
}