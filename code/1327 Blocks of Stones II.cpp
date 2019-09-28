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
		for (i = 1; i < n; i++) {//需要合并n-1次
			//取出最小的两个石堆合并
			a = q.top(); q.pop(); x += a;
			b = q.top(); q.pop(); x += b;
			//合并完再放入优先队列中
			q.push(a + b);
		}
		q.pop();//将最后一个石堆从优先队列中弹出
		printf("%d\n", x);
	}
}