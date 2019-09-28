#define gets_s(s) gets(s)
#include<iostream>
int main() {
	char mi[26], str[100];
	int i;
	while (scanf("%s", mi) != EOF) {
		getchar();
		gets(str);
		for (i = 0; i < strlen(str); i++) {
			if (str[i] >= 'A'&&str[i] <= 'Z') {
				str[i] = mi[str[i] - 'A'];
			}
			else if (str[i] >= 'a'&&str[i] <= 'z') {
				str[i] = mi[str[i] - 'a'] - 'A' + 'a';
			}
		}
		printf("%s\n", str);
	}
	return 0;
}