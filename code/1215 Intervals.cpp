#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int l, r;
	node(){}
	node(int l,int r):l(l),r(r){}
}node;
node list[50000];
//lֵС���������ȣ�lֵ��ͬrֵ�������
//���������꣬��˳���ȡʱ������lֵ��ͬ�����䲻���ٸ���rֵ
bool listsort(node a, node b) {
	if (a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}
int main() {
	int n, l, r, i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d%d", &l, &r);
			list[i] = node(l, r);
		}
		sort(list, list + n, listsort);
		//��l��r����ֵ
		l = list[0].l; r = list[0].r;
		//ֻҪ�����lֵ�����Ѵ��rֵ��˵������Ͽ���������Ѵ��l��r
		for (i = 1; i < n; i++) {
			if (list[i].l<=r&&list[i].r>r) r = list[i].r;
			else if (list[i].l > r) {
				printf("%d %d\n", l, r);
				l = list[i].l; r = list[i].r;
			}
		}
		//�����ж���ϣ�������һ�������һ�пհ���
		printf("%d %d\n\n", l, r);
	}
}