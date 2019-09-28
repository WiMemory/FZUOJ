#include<iostream>

int m, n;
char mn[100][100];
//���mn[i][j]�Ƿ��е���
bool check(int i,int j) {
	if (i < 0 || i >= m || j < 0 || j >= n || mn[i][j] != '*') return false;
	else return true;
}
//����ij�����ж��ٿŵ��ף���������Ӧ����
void findmines(int i,int j) {
	int sum_mines = 0;
	if (check(i - 1, j - 1)) { //����
		++sum_mines;
	}
	if (check(i - 1, j)) { //����
		++sum_mines;
	}
	if (check(i - 1, j + 1)) { //����
		++sum_mines;
	}
	if (check(i, j - 1)) { //����
		++sum_mines;
	}
	if (check(i, j + 1)) { //����
		++sum_mines;
	}
	if (check(i + 1, j - 1)) { //����
		++sum_mines;
	}
	if (check(i + 1, j)) { //����
		++sum_mines;
	}
	if (check(i + 1, j + 1)) { //����
		++sum_mines;
	}
	mn[i][j] = (char)(sum_mines + '0');
}
int main() {
	int i, j;
	while (scanf("%d%d", &m, &n) != EOF) {
		getchar();
		if (m == 0) break;
		memset(mn, '\0', 10000);
		//����
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				mn[i][j] = getchar();
			}
			getchar();
		}
		//ɨ��
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (mn[i][j] == '.') {
					findmines(i, j);
				}
			}
		}
		//���
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				printf("%c", mn[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}