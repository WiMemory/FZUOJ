#include<iostream>
#include<cmath>
char str[100 + 5];
char num[32 + 5];
bool flag;
int char2int() {
	int i, ans = 0;
	i = strlen(num)-1;
	for (; i >= 0; i--) {
		ans += (num[i] - '0') * pow(10, strlen(num) - 1 - i);
	}
	return ans;
}
int main() {
	int i, len, j, ans;
	while (scanf("%s", str) != EOF) {
		flag = true;
		len = strlen(str);
		ans = 0;
		//先处理第一个元素
		for (i = 0; i < len;i++) {
			//去掉前导零
			while (str[i] == '0') {
				++i;
			}
			//用于考虑元素为000?的情况
			if (str[i] == '\0') {
				break;
			}
			else if (str[i] == '+') {
				continue;
			}
			else if (str[i] == '-') {
				flag = false;
				continue;
			}
			j = 0;
			while (str[i] >= '0'&&str[i] <= '9') {
				num[j] = str[i];
				++i; ++j;
			}
			num[j] = '\0';
			if (flag) {
				ans += char2int();
			}
			else {
				ans -= char2int();
			}
			break;
		}
		if (str[i] != '\0') {
			while(i < len) {
				if (str[i] == '+') {
					++i;
					//去掉前导零
					while (str[i] == '0') {
						++i;
					}
					//用于考虑元素为000?的情况
					if (str[i] == '\0') {
						break;
					}
					else if (str[i] == '+') {
						continue;
					}
					else if (str[i] == '-') {
						flag = false;
						continue;
					}
					j = 0;
					while (str[i] >= '0'&&str[i] <= '9') {
						num[j] = str[i];
						++i; ++j;
					}
					num[j] = '\0';
					if (flag) {
						ans += char2int();
					}
					else {
						ans -= char2int();
					}
				}
				else if (str[i] == '-') {
					++i;
					//去掉前导零
					while (str[i] == '0') {
						++i;
					}
					j = 0;
					while (str[i] >= '0'&&str[i] <= '9') {
						num[j] = str[i];
						++i; ++j;
					}
					num[j] = '\0';
					ans -= char2int();
					flag = false;
				}
			}
		}
		printf("%d\n", ans);
	}
}