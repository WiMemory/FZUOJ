#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
	int n, i, x, a, b;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			q.push(x);
		}
		x = 0;
		for (i = 1; i < n; i++) {//��Ҫ�ϲ�n-1��
			//ȡ����С������ʯ�Ѻϲ�
			a = q.top(); q.pop(); x += a;
			b = q.top(); q.pop(); x += b;
			//�ϲ����ٷ������ȶ�����
			q.push(a + b);
		}
		q.pop();//�����һ��ʯ�Ѵ����ȶ����е���
		printf("%d\n", x);
	}
}