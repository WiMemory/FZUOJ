#include<iostream>

struct node {
	int RP;//RPֵ
	int num;//�±�
}queue[1000010];

int main() {
	int T;
	char name[6];
	int RP;
	//headָ����ף�clean��ʾ�ѳ���������rearָ���β��num��ʾ���������
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
			//�������ӵ�������RPֵ������RP���ߣ�Ӧ��Ѱ�ҵ��ʵ�λ�ò�����
			else {
				//��rearλ�ÿ�ʼ��ǰѰ�ң�ֱ��RP<queue[rear-1].RP
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
			//���RP���߳��ӣ���һ��RP���߼�Ϊ++head
			if (++clean == queue[head].num) {
				++head;
			}
			break;
		case 'E':
			//Ӧ�����������ݽ��г�ʼ��
			head = 1, clean = 0, rear = 1, num = 0;
			queue[1].RP = 0;
			queue[1].num = 0;
			--T;
			break;
		}
	}
}