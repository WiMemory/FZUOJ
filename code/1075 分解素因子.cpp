#include<iostream>
#include<cmath>
//�ж��Ƿ�������
bool checkprime(int a) {
	int i;
	//�ж�����ʱֻ��Ҫ�жϵ�a��ƽ����
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
			//���n������������ô��2-sqrt(n)��Χ�ڱ���һ��n���������ӣ��ҳ������
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