#include<iostream>

int main() {
	int i;
	char str[51];
	while (gets_s(str) != NULL) {
		for (i = 0; i < strlen(str); i++) {
			if (str[i] >= 'A'&&str[i] <= 'Z') {
				str[i] = str[i] - 'A' + 'a';
			}
		}
		printf("%s\n", str);
		memset(str, '\0', 51);
	}
}