#include<iostream>
#include<algorithm>
using namespace std;
typedef struct node {
	int x, y, num;
	node(){}
	node(int x, int y, int num) :x(x), y(y), num(num) {}
}node;
node list[2500];
bool numsort(node a, node b) {
	return a.num > b.num;
}
int main() {
	int T, M, N, K;
	int i, j, m;
	int f;//�нỨ�����������
	int ans, t;
	int x, y;//λ��
	scanf("%d", &T);
	while (T--) {
		t = ans = f = 0;
		scanf("%d%d%d", &M, &N, &K);
		for (i = 1; i <= M; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &m);
				//ע��˴�iΪ������jΪ������
				if (m) list[f++] = node(j, i, m);
			}
		}
		sort(list, list + f, numsort);
		x = list[0].x; y = list[0].y;
		t += list[0].y;//���ϵ����һ���������ʱ��
		for (i = 0; i < f; i++) {
			//���ȥ��һ���������ܹ���Kʱ������ɲ�ժ�ͻص�·�ߵ��������¼������������
			if (t + list[i].y + 1 + abs(list[i].x - x) + abs(list[i].y - y) <= K) {
				t += 1 + abs(list[i].x - x) + abs(list[i].y - y);
				x = list[i].x; y = list[i].y;//���µ�ǰλ��
				ans += list[i].num;
			}
			else break;
		}
		printf("%d\n", ans);
	}
}