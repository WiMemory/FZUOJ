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
		int o; //相交面积
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
	double x;//坐标x
	double y;//坐标y
}Point;
typedef struct Rectangle {
	Point p1;//左下角的点
	Point p2;//右上角的点
}Rectangle;
//R12是R1和R2相交的矩形
Rectangle R1, R2, R12;

//计算矩形面积
double area(Rectangle r) {
	return (r.p2.x - r.p1.x)*(r.p2.y - r.p1.y);
}
//找出矩形r1、r2的重叠矩形r
//两个矩形相交的部分 其p1的x是两个矩形x的最大值，y同理 p2的x是两个矩形x的最小值，y同理
//并且只有p2在p1右上角时 两个矩形才相交
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
