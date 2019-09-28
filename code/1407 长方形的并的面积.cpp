#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Point {
	int x;//����x
	int y;//����y
}Point;
typedef struct Rectangle {
	Point p1;//���½ǵĵ�
	Point p2;//���Ͻǵĵ�
}Rectangle;
//R12��R1��R2�ཻ�ľ���
Rectangle R1, R2, R3, R12;

//����������
int area(Rectangle r) {
	return (r.p2.x - r.p1.x)*(r.p2.y - r.p1.y);
}
//�ҳ�����r1��r2���ص�����r
//���������ཻ�Ĳ��� ��p1��x����������x�����ֵ��yͬ�� p2��x����������x����Сֵ��yͬ��
//����ֻ��p2��p1���Ͻ�ʱ �������β��ཻ
Rectangle overlap(Rectangle r1, Rectangle r2) {
	Rectangle r;
	r.p1.x = max(r1.p1.x, r2.p1.x);
	r.p1.y = max(r1.p1.y, r2.p1.y);
	r.p2.x = min(r1.p2.x, r2.p2.x);
	r.p2.y = min(r1.p2.y, r2.p2.y);
	if (!(r.p2.x > r.p1.x) || !(r.p2.y > r.p1.x)) {
		r.p1.x = r.p1.y = r.p2.x = r.p2.y = 0;
	}
	return r;
}

int main() {
	int n, ans;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d", &R1.p1.x, &R1.p2.x, &R1.p1.y, &R1.p2.y);
		scanf("%d%d%d%d", &R2.p1.x, &R2.p2.x, &R2.p1.y, &R2.p2.y);
		scanf("%d%d%d%d", &R3.p1.x, &R3.p2.x, &R3.p1.y, &R3.p2.y);
		ans = area(R1) + area(R2) + area(R3);
		R12 = overlap(R1, R2);
		ans -= area(R12);
		ans -= area(overlap(R1, R3));
		ans -= area(overlap(R2, R3));
		ans += area(overlap(R12, R3));
		printf("%d\n", ans);
	}
	return 0;
}