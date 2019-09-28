#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
struct Pos {
	double x, y;
}island[1005];
struct Block {
	double left, right;
}block[1005];
//排序函数 
bool cmp(Block a, Block b) {
	if (a.right != b.right) return a.right < b.right;
	else return a.left > b.left;
}
int main() {
	double d;    //雷达半径   
	int n, m;    //岛的个数 雷达个数 
	bool bo;     //是否违规 
	int c = 1;   //情况序号 
	while (~scanf("%d %lf", &n, &d) && n != 0 && d != 0) {
		bo = true;
		m = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &island[i].x, &island[i].y);
			if (island[i].y > d) {//如果小岛离海岸的距离比雷达半径还大，就无解 
				bo = false;
			}
			//求以小岛为圆心，雷达半径 d 为半径的圆 O 在海岸的左右交点 
			block[i].left = (island[i].x - (double)sqrt(d*d - island[i].y*island[i].y));
			block[i].right = (island[i].x + (double)sqrt(d*d - island[i].y*island[i].y));
		}
		if (!bo) {
			printf("Case %d: -1\n", c++);//无解输出 -1 
		}
		else {
			std::sort(block, block + n, cmp);//对区间排序 
			double temp = -999999;
			for (int i = 0; i < n; i++) {
				if (block[i].left > temp) {//区间选点问题 
					temp = block[i].right;
					m++;
				}
			}
			printf("Case %d: %d\n", c++, m);
		}
	}
}