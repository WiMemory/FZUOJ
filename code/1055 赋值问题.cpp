#include<iostream>
char int2char(int a) {
	return a + 'a';
}
int char2int(char a) {
	return a - 'a';
}
int main() {
	bool flag = false;
	int N, i;
	char l, r;
	int chars[26];
	memset(chars, 0, sizeof(chars));
	chars[0] = 1;
	while (scanf("%d", &N) != EOF && N != -1) {
		getchar();
		for (i = 0; i < N; i++) {
			scanf("%c=%c", &l, &r);
			getchar();
			chars[char2int(l)] = chars[char2int(r)];
		}
		for (i = 0; i < 26; i++) {
			if (chars[i] == 1) {
				printf("%c", int2char(i));
				flag = true;
				++i;
				break;
			}
		}
		for (; i < 26; i++) {
			if (chars[i] == 1) {
				printf(" %c", int2char(i));
			}
		}
		if (!flag) {
			printf("none");
		}
		printf("\n");
		memset(chars, 0, sizeof(chars));
		chars[0] = 1;
		flag = false;
	}
}