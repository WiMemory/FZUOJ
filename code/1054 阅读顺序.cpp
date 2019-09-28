#include<iostream>
using namespace std;
int main() {
	int n, i;
	char str[201];
	scanf("%d", &n);
	getchar();
	while (n--) {
		memset(str, '\0', 201);
		gets_s(str);
		for (i = strlen(str) - 1; i >= 0; i--) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
}