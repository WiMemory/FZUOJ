#include<iostream>
int max(int a, int b) {
	return a > b ? a : b;
}
int a[1001][1001];
int main() {
	int R;
	int i, j;
	//int a[1001][1001];
	//a���鲻���ڴ˴����壬�ᷢ��ջ�����ԭ�������ⳬ���˱������Ծֲ������ռ��СԤ���ֵ
	//vs2017 ������ϢΪ��0x00B91899 ����δ��������쳣(�� FZUOJ.exe ��): 0xC00000FD: Stack overflow (����: 0x00000000, 0x002E2000)��
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