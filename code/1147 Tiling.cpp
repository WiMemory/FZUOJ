#include<iostream>
using namespace std;
int F[251][100];
void init() {
	memset(F, 0, sizeof(F));
	F[1][0] = 1;
	F[2][0] = 3;
	int i, c, j;
	for (i = 3; i <= 250; i++) {
		c = 0;
		for (j = 0; j <= 100; j++)
		{
			F[i][j] = F[i - 1][j] + 2 * F[i - 2][j] + c;
			c = F[i][j] / 10;
			F[i][j] %= 10;
		}
	}
}
int main() {
	int n, i, j;
	init();
	while (cin >> n) {
		if (n == 0)
			cout << 1 << endl;
		else
		{
			for (i = 99; i >= 0; i--)
				if (F[n][i])
					break;
			for (j = i; j >= 0; j--)
				cout << F[n][j];
			cout << endl;
		}
	}
}