#include<iostream>
int max(int a, int b) {
	return a > b ? a : b;
}
int a[1001][1001];
int main() {
	int R;
	int i, j;
	//int a[1001][1001];
	//a数组不能在此处定义，会发生栈溢出，原因在于这超出了编译器对局部变量空间大小预设的值
	//vs2017 报错信息为：0x00B91899 处有未经处理的异常(在 FZUOJ.exe 中): 0xC00000FD: Stack overflow (参数: 0x00000000, 0x002E2000)。
	while (scanf("%d", &R) != EOF) {
		for (i = 0; i < R; i++) {
			for (j = 0; j < i + 1; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = R - 2; i >= 0; i--) {
			for (j = 0; j < i + 1; j++) {
				a[i][j] = max(a[i + 1][j], a[i + 1][j + 1]) + a[i][j];
			}
		}
		printf("%d\n", a[0][0]);
	}
}