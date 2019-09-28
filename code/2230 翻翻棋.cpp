#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	int T, i, j;
	char x;
	int rx, ry, bx, by;
	int len;
	cin >> T;
	while (T--) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 8; j++) {
				cin >> x;
				if (x == '*') {
					rx = j;
					ry = i;
				}
				else if (x == '.') {
					bx = j;
					by = i;
				}
			}
		}
		len = abs(bx - rx) + abs(by - ry);
		printf("%s win\n", (len % 2 == 0) ? "Black" : "Red");
	}
}