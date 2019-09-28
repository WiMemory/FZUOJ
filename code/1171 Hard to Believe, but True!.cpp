#include <stdio.h>
#include <string.h>
#define LEN strlen(str)
int f(char s[]);
char str[15];
int main()
{
	while (~scanf("%s", str)) {
		char s[3][15];
		int i, p1, p2, v;
		for (i = 0; i < LEN; i++) {//找到“+”和“=”的位置
			if (str[i] == '+')
				p1 = i;
			if (str[i] == '=')
				p2 = i;
		}
		//存成3个字符串
		for (v = 0, i = 0; i < p1; i++)
			s[0][v++] = str[i];
		s[0][v] = 0;
		for (v = 0, i = p1 + 1; i < p2; i++)
			s[1][v++] = str[i];
		s[1][v] = 0;
		for (v = 0, i = p2 + 1; i < LEN; i++)
			s[2][v++] = str[i];
		s[2][v] = 0;
		printf("%s\n", (f(s[0]) + f(s[1]) == f(s[2])) ? "True" : "False");
		if (!strcmp(str, "0+0=0"))
			break;
	}
	return 0;
}
int f(char s[]) {
	int len = strlen(s);
	int i, p = 0, sum = 0;
	for (i = len - 1; i > 0; --i) {//去掉所有前导0
		if (s[i] != '0') {
			p = i;
			break;
		}
	}
	for (i = p; i >= 0; --i)//转换成数字
		sum = (sum + s[i] - '0') * 10;
	return sum;
}