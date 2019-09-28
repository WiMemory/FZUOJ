#include<iostream>
#include <math.h>
int M[1000001];
int main() {
	int N;
	double x = 1;
	for (int i = 1; i <= 1000000; i++) {
		x += log10(double(i));
		M[i] = floor(x);
	}
	while (scanf("%d", &N) != EOF) {
		printf("%d\n", M[N]);
	}
}