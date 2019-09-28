# Problem 1215 Intervals

### Accept: 80    Submit: 297 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

There is given the series of n closed intervals [ai,bi], where i=1,2,...,n. The sum of those intervals may be represented as a sum of closed pairwise non-intersecting intervals. The task is to find such representation with the minimal number of intervals. The intervals of this representation should be written in the output file in acceding order.

We say that the intervals [a,b] and [c,d] are in ascending order,if and only if a <= b < c <= d.



### Task

Write a program which:

- reads from the input file the description of the series of intervals
- computes pairwise non-intersecting intervals satisfying the conditions given above
- Output the computed intervals in ascending order

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

There several test cases. In the first line each case there is one integer n, 3 <= n <= 50000. This is the number of intervals. In the (i+1)-st line, 1 <= i <= n, there is a description of the interval [ai; bi] in the form of two integers ai and bi separated by a single space, which are respectively the beginning and the end of the interval, 1 <= ai <= bi <= 1000000.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

The output of each case should contain descriptions of all computed pairwise non-intersecting intervals. In each line should be written a description of one interval. It should be composed of two integers, separated by a single space, the beginning and the end of the interval respectively. The intervals should be written into the output file in ascending order. Output a blank line after each case.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

>5
>5 6
>1 4
>10 10
>6 9
>8 10

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 1 4
> 5 10

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

POI 01

## 解决方案

简单排序题

```cpp
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int l, r;
	node(){}
	node(int l,int r):l(l),r(r){}
}node;
node list[50000];
//l值小的区间优先，l值相同r值大的优先
//这样排序完，按顺序读取时，碰到l值相同的区间不必再更新r值
bool listsort(node a, node b) {
	if (a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}
int main() {
	int n, l, r, i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d%d", &l, &r);
			list[i] = node(l, r);
		}
		sort(list, list + n, listsort);
		//给l，r赋初值
		l = list[0].l; r = list[0].r;
		//只要区间的l值大于已存的r值即说明区间断开，则输出已存的l，r
		for (i = 1; i < n; i++) {
			if (list[i].l<=r&&list[i].r>r) r = list[i].r;
			else if (list[i].l > r) {
				printf("%d %d\n", l, r);
				l = list[i].l; r = list[i].r;
			}
		}
		//区间判断完毕，输出最后一个区间加一行空白行
		printf("%d %d\n\n", l, r);
	}
}
```

