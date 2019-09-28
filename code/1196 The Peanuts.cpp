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
	int f;//有结花生的苗的数量
	int ans, t;
	int x, y;//位置
	scanf("%d", &T);
	while (T--) {
		t = ans = f = 0;
		scanf("%d%d%d", &M, &N, &K);
		for (i = 1; i <= M; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &m);
				//注意此处i为纵坐标j为横坐标
				if (m) list[f++] = node(j, i, m);
			}
		}
		sort(list, list + f, numsort);
		x = list[0].x; y = list[0].y;
		t += list[0].y;//加上到达第一处花生苗的时间
		for (i = 0; i < f; i++) {
			//如果去下一处花生苗能够在K时间内完成采摘和回到路边的任务则记录，否则输出结果
			if (t + list[i].y + 1 + abs(list[i].x - x) + abs(list[i].y - y) <= K) {
				t += 1 + abs(list[i].x - x) + abs(list[i].y - y);
				x = list[i].x; y = list[i].y;//更新当前位置
				ans += list[i].num;
			}
			else break;
		}
		printf("%d\n", ans);
	}
}