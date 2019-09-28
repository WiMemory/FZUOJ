#include<iostream>
#include<algorithm>
using namespace std;
typedef struct Point {
	int x;//坐标x
	int y;//坐标y
}Point;
typedef struct Rectangle {
	Point p1;//左下角的点
	Point p2;//右上角的点
}Rectangle;
//R12是R1和R2相交的矩形
Rectangle R1, R2, R3, R12;

//计算矩形面积
int area(Rectangle r) {
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