#include<iostream>

int m, n;
char mn[100][100];
//检查mn[i][j]是否有地雷
bool check(int i,int j) {
	if (i < 0 || i >= m || j < 0 || j >= n || mn[i][j] != '*') return false;
	else return true;
}
//查找ij附近有多少颗地雷，并填入相应数字
void findmines(int i,int j) {
	int sum_mines = 0;
	if (check(i - 1, j - 1)) { //左上
		++sum_mines;
	}
	if (check(i - 1, j)) { //正上
		++sum_mines;
	}
	if (check(i - 1, j + 1)) { //右上
		++sum_mines;
	}
	if (check(i, j - 1)) { //正左
		++sum_mines;
	}
	if (check(i, j + 1)) { //正右
		++sum_mines;
	}
	if (check(i + 1, j - 1)) { //左下
		++sum_mines;
	}
	if (check(i + 1, j)) { //正下
		++sum_mines;
	}
	if (check(i + 1, j + 1)) { //右下
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
		//输入
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				mn[i][j] = getchar();
			}
			getchar();
		}
		//扫雷
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (mn[i][j] == '.') {
					findmines(i, j);
				}
			}
		}
		//输出
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				printf("%c", mn[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}