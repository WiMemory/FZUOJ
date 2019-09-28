#include<iostream>

struct node {
	int RP;//RP值
	int num;//下标
}queue[1000010];

int main() {
	int T;
	char name[6];
	int RP;
	//head指向队首，clean表示已出队人数，rear指向队尾，num表示已入队人数
	int head = 1, clean = 0, rear = 1, num = 0;
	queue[1].RP = 0;
	queue[1].num = 0;
	scanf("%d", &T);
	while (T) {
		scanf("%s", name);
		switch (name[0]) {
		case 'C':
			scanf("%s %d", name, &RP);
			++num;
			if (RP >= queue[head].RP) {
				queue[rear].num = num;
				queue[rear].RP = RP;
				head = rear;
				++rear;
			}
			//如果新入队的面试者RP值不大于RP王者，应当寻找到适当位置并插入
			else {
				//从rear位置开始往前寻找，直到RP<queue[rear-1].RP
				while (RP >= queue[--rear].RP);
				++rear;
				queue[rear].num = num;
				queue[rear].RP = RP;
				++rear;
			}
			break;
		case 'Q':
			if (clean < num) {
				printf("%d\n", queue[head].RP);
			}
			else
				printf("-1\n");
			break;
		case 'G':
			//如果RP王者出队，下一个RP王者即为++head
			if (++clean == queue[head].num) {
				++head;
			}
			break;
		case 'E':
			//应当对如下数据进行初始化
			head = 1, clean = 0, rear = 1, num = 0;
			queue[1].RP = 0;
			queue[1].num = 0;
			--T;
			break;
		}
	}
}