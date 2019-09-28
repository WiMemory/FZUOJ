#include<iostream>
using namespace std;
int arry[1000000];
char op[4];
int oparr[3], n;
int opn, L, R;
void AND() {
	scanf("%d%d%d", &opn, &L, &R);
	int i;
	for (i = L; i <= R; i++) {
		arry[i] &= opn;
	}
}
void OR() {
	scanf("%d%d%d", &opn, &L, &R);
	int i;
	for (i = L; i <= R; i++) {
		arry[i] |= opn;
	}
}
void XOR() {
	scanf("%d%d%d", &opn, &L, &R);
	int i;
	for (i = L; i <= R; i++) {
		arry[i] ^= opn;
	}
}
void SUM() {
	scanf("%d%d", &L, &R);
	int sum = 0, i;
	for (i = L; i <= R; i++) {
		sum += arry[i];
	}
	cout << sum << endl;
}
int main() {
	int T, m, i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%d", &arry[i]);
		}
		getchar();
		for (i = 0; i < m; i++) {
			scanf("%s", op);
			switch (op[0]) {
			case 'A':
				AND();
				break;
			case 'O':
				OR();
				break;
			case 'X':
				XOR();
				break;
			case 'S':
				SUM();
				break;
			}
		}
	}
}