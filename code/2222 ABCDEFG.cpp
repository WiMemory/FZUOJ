#define gets(x) gets_s(x)
#include<iostream>
using namespace std;
char work[100 + 5];
int main() {
	int T, l, i, ans;
	scanf("%d", &T);
	getchar();
	while (T--) {
		gets(work);
		ans = 0;
		l = strlen(work);
		for (i = 0; i < l; i++) {
			switch (work[i]) {
			case 'A':
				ans += 3; break;
			case 'a':
				ans += 1; break;
			case 'B':
				ans += 2; break;
			case 'b':
				ans += 1; break;
			case 'C':
				ans += 1; break;
			case 'c':
				ans += 1; break;
			case 'D':
				ans += 2; break;
			case 'd':
				ans += 2; break;
			case 'E':
				ans += 3; break;
			case 'e':
				ans += 1; break;
			case 'F':
				ans += 3; break;
			case 'f':
				ans += 2; break;
			case 'G':
				ans += 1; break;
			case 'g':
				ans += 1; break;
			}
		}
		printf("%d\n", ans);
	}
}