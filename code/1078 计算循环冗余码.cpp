#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[30];
char b[] = "10011";

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		getchar();
		scanf("%s", str);
		strcat(str, "0000");
		int len = strlen(str);
		for (int i = 0; i < len - 4; ++i) {
			if (str[i] == '0')
				continue;
			int k = i;
			for (int j = 0; j < 5; ++j, ++k) {
				if (str[k] ^ b[j])
					str[k] = '1';
				else
					str[k] = '0';
			}
		}
		for (int i = len - 5; i < len; ++i)
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}