#define gets(x) gets_s(x)
#include<iostream>
#include<algorithm>
using namespace std;
char str1[105], str2[105];
bool mysort(char a, char b) {
	return a < b ? true : false;
}
int main() {
	int T, n, i, ans, len;
	n = 1;
	scanf("%d", &T);
	while (n <= T) {
		ans = 0;
		scanf("%d", &len);
		getchar();
		gets(str1);
		for (i = 0; i < len; i++) {
			str2[i] = str1[i];
		}
		sort(&str1[0], &str1[len],mysort);
		for (i = 0; i < len; i++) {
			if (str1[i] != str2[i]) {
				++ans;
			}
		}
		printf("Case %d: %d\n", n, ans);
		++n;
	}
}