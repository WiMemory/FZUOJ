#include<iostream>
#include<cmath>
//判断是否是质数
bool checkprime(int a) {
	int i;
	//判断质数时只需要判断到a的平方根
	for (i = 2; i <= sqrt(a); i++) {
		if (a%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int k, n, i;
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		while (!checkprime(n)) {
			//如果n不是质数，那么在2-sqrt(n)范围内必有一个n的质数因子，找出并输出
			for (i = 2; i <= sqrt(n); i++) {
				if (!checkprime(i)) continue;
				else {
					if (n%i == 0) {
						n = n / i;
						printf("%d", i);
						break;
					}
				}
			}
			printf("*");
		}
		printf("%d\n", n);
	}
}