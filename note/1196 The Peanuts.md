# Problem 1196 The Peanuts

### Accept: 112    Submit: 253 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

Mr. Robinson and his pet monkey Dodo love peanuts very much. One day while they were having a walk on a country road, Dodo found a sign by the road, pasted with a small piece of paper, saying "Free Peanuts Here! " You can imagine how happy Mr. Robinson and Dodo were.

There was a peanut field on one side of the road. The peanuts were planted on the intersecting points of a grid as shown in Figure-1. At each point, there are either zero or more peanuts. For example, in Figure-2, only four points have more than zero peanuts, and the numbers are 15, 13, 9 and 7 respectively. One could only walk from an intersection point to one of the four adjacent points, taking one unit of time. It also takes one unit of time to do one of the following: to walk from the road to the field, to walk from the field to the road, or pick peanuts on a point.

![img](http://acm.fzu.edu.cn/image/Problem/1196.gif)

According to Mr. Robinson's requirement, Dodo should go to the plant with the most peanuts first. After picking them, he should then go to the next plant with the most peanuts, and so on. Mr. Robinson was not so patient as to wait for Dodo to pick all the peanuts and he asked Dodo to return to the road in a certain period of time. For example, Dodo could pick 37 peanuts within 21 units of time in the situation given in Figure-2.

Your task is, given the distribution of the peanuts and a certain period of time, tell how many peanuts Dodo could pick. You can assume that each point contains a different amount of peanuts, except 0, which may appear more than once.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

The first line of input contains the test case number T (1 <= T <= 20). For each test case, the first line contains three integers, M, N and K (1 <= M, N <= 50, 0 <= K <= 20000). Each of the following M lines contain N integers. None of the integers will exceed 3000. (M * N) describes the peanut field. The j-th integer X in the i-th line means there are X peanuts on the point (i, j). K means Dodo must return to the road in K units of time.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each test case, print one line containing the amount of peanuts Dodo can pick.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 2
> 6 7 21
> 0 0 0 0 0 0 0
> 0 0 0 0 13 0 0
> 0 0 0 0 0 0 7
> 0 15 0 0 0 0 0
> 0 0 0 9 0 0 0
> 0 0 0 0 0 0 0
> 6 7 20
> 0 0 0 0 0 0 0
> 0 0 0 0 13 0 0
> 0 0 0 0 0 0 7
> 0 15 0 0 0 0 0
> 0 0 0 9 0 0 0
> 0 0 0 0 0 0 0

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 37
>
> 28

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

2004 Beijing Preliminary

## 解决方案

本题的主人公很贪心，有强迫症，必须要从结最多花生的花生苗开始采摘

（辛亏主人公一根筋，不然问题就复杂了）

那么我们就可以给花生苗排序一下，依次判断该花生苗够不够时间采摘

详见代码

```cpp
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
```

