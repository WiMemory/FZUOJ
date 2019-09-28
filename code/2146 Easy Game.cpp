#define gets(s) gets_s(s)
#include<iostream>
int main() {
	int T, i = 0;
	scanf("%d", &T);
	getchar();
	char str[10088];
	while (T--) {
		gets(str);
		printf("Case %d: ", ++i);
		if (strlen(str) % 2 == 0) {
			printf("Even\n");
		}
		else printf("Odd\n");
	}
}