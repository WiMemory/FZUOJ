/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int x1, y1, w1, h1, x2, y2, w2, h2;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> x1 >> y1 >> w1 >> h1;
		cin >> x2 >> y2 >> w2 >> h2;
		int o; //�ཻ���
		if (min(x1 + w1, x2 + w2) - max(x1, x2) > 0 && min(y1 + h1, y2 + h2) - max(y1, y2) > 0)
			o = (min(x1 + w1, x2 + w2) - max(x1, x2)) * (min(y1 + h1, y2 + h2) - max(y1, y2));
		else
			o = 0;
		double ans;
		ans = (double)o / (w1 * h1 + w2 * h2 - o);
		printf("%.2f\n", ans);
	}
	return 0;
}
*/

#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Point {
	double x;//����x
	double y;//����y
}Point;
typedef struct Rectangle {
	Point p1;//���½ǵĵ�
	Point p2;//���Ͻǵĵ�
}Rectangle;
//R12��R1��R2�ཻ�ľ���
Rectangle R1, R2, R12;

//����������
double area(Rectangle r) {
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
	int n;
	scanf("%d", &n);
	double w, h, ans;
	while (n--) {
		scanf("%lf%lf%lf%lf", &R1.p1.x, &R1.p1.y, &w, &h);
		R1.p2.x = R1.p1.x + w;
		R1.p2.y = R1.p1.y + h;
		scanf("%lf%lf%lf%lf", &R2.p1.x, &R2.p1.y, &w, &h);
		R2.p2.x = R2.p1.x + w;
		R2.p2.y = R2.p1.y + h;
		R12 = overlap(R1, R2);
		ans = area(R12);
		printf("%.2lf\n", ans / (area(R1) + area(R2) - ans));
	}
	return 0;
}
