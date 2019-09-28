#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int l, r;
	node(){}
	node(int l,int r):l(l),r(r){}
}node;
node list[50000];
//l值小的区间优先，l值相同r值大的优先
//这样排序完，按顺序读取时，碰到l值相同的区间不必再更新r值
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
		//给l，r赋初值
		l = list[0].l; r = list[0].r;
		//只要区间的l值大于已存的r值即说明区间断开，则输出已存的l，r
		for (i = 1; i < n; i++) {
			if (list[i].l<=r&&list[i].r>r) r = list[i].r;
			else if (list[i].l > r) {
				printf("%d %d\n", l, r);
				l = list[i].l; r = list[i].r;
			}
		}
		//区间判断完毕，输出最后一个区间加一行空白行
		printf("%d %d\n\n", l, r);
	}
}