#include<iostream>
using namespace std;
int main() {
	int ans = 0;
	char str[4];
	while (cin >> str) {
		++ans;
		if (strcmp(str, "END") == 0) {
			//printf("%c %d\n", --ans % 2 ? 'B' : 'W', ans);//此种写法oj上WA，原因未知
			printf("%c %d\n", (ans - 1) % 2 ? 'B' : 'W', ans - 1);
			ans = 0;
		}
	}
}