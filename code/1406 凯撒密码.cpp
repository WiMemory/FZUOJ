#define gets(s) gets_s(s)
#include<iostream>
int main() {
	int i;
	char str[80];
	while (gets(str) != NULL) {
		for (i = 0; i < strlen(str); i++) {
			if (str[i] <= 'Z'&&str[i] >= 'A') {
				str[i] = (str[i] - 'A' + 26 - 3) % 26 + 'A';
			}
			else if (str[i] <= 'z'&&str[i] >= 'a') {
				str[i] = (str[i] - 'a' + 26 - 3) % 26 + 'a';
			}
		}
		printf("%s\n", str);
	}
}