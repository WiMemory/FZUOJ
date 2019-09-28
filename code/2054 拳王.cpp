#include<iostream>
int main() {
	int T, i, m, max;
	bool flag;
	scanf("%d", &T);
	while (T--) {
		flag = max = 0;
		for (i = 0; i < 6; i++) {
			scanf("%d", &m);
			if (m > max) {
				max = m;
				if(i>=3){
					flag = 1;
				}
			}
		}
		printf("%d\n", flag ? 2 : 1);
	}
}