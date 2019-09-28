#include<iostream>
#include<string>
using namespace std;
typedef struct node {
	string s;
	int num;
}node;
node arry[100001];
char inp[7];
int main() {
	int n, i, x, a, b, flag, j;
	while (scanf("%d", &n) != EOF) {
		cin >> arry[0].s;
		arry[0].num = 0;
		for (i = 0; i < n; i++) {
			if (arry[0].s[i] == '1') ++arry[0].num;
		}
		scanf("%d", &x);
		flag = 1;
		for (i = 0; i < x; i++) {
			scanf("%d%d", &a, &b);
			switch (a) {
			case 1:
				arry[flag].s += arry[flag - 1].s;
				if (arry[flag].s[b - 1] == '0') {
					arry[flag].s[b - 1] = '1';
					arry[flag].num = arry[flag - 1].num + 1;
				}
				else if (arry[flag].s[b - 1] == '1') {
					arry[flag].s[b - 1] = '0';
					arry[flag].num = arry[flag - 1].num - 1;
				}
				printf("%d\n", arry[flag].num);
				++flag;
				break;
			case 2:
				flag = b;
				printf("%d\n", arry[flag].num);
				++flag;
				break;
			}
		}
	}
}