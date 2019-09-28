# Problem 1004 Number Triangle

### Accept: 2450    Submit: 6555 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

Consider the number triangle shown below. Write a program that calculates the highest sum of numbers that can be passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right.

```c++
        7

      3   8

    8   1   0

  2   7   4   4

4   5   2   6   5
```

In the sample above, the route from 7 to 3 to 8 to 7 to 5 produces the highest sum: 30.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

There are multiple test cases.The first line of each test case contains R (1 <= R <= 1000), the number of rows. Each subsequent line contains the integers for that particular row of the triangle. All the supplied integers are non-negative and no larger than 100.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

Print a single line containing the largest sum using the traversal specified for each test case.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

```c++
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
```



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

```c++
30
```

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

IOI 95

## 解决思路1

递归求解

```cpp
#include<iostream>
int R, max = 0;
int a[1000][1000];
void count(int sum, int i, int j) {
	if (i >= R) {
		max = sum > max ? sum : max;
		return;
	}
	sum += a[i][j];
	count(sum, i + 1, j);
	count(sum, i + 1, j + 1);
}
int main() {
	int i, j;
	while (scanf("%d", &R) != EOF) {
		max = 0;
		memset(a, 0, 1000000);
		for (i = 0; i < R; i++) {
			for (j = 0; j < i + 1; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		count(0, 0, 0);
		printf("%d\n", max);
	}
}
```

结果Time Limit Exceed

原因在于递归函数会不断调用自身，复杂度呈指数上升，并且需要占用许多资源用于保护现场。

## 解决思路2

后经过百度，这是一类基础的数塔问题，则可以使用**动态规划**思想来解决。

> 在用动态规划考虑数塔问题时可以自顶向下的分析，自底向上的计算。
>
> 从顶点出发时到底向左走还是向右走应取决于是从左走能取到最大值还是从右走能取到最大值，只要左右两道路径上的最大值求出来了才能作出决策。同样的道理下一层的走向又要取决于再下一层上的最大值是否已经求出才能决策。这样一层一层推下去，直到倒数第二层时就非常明了。 

```cpp
#include<iostream>
int max(int a,int b) {
	return a > b ? a : b;
}
int a[1001][1001];
int main() {
	int R;
	int i, j;
    //int a[1001][1001];
    //a数组不能在此处定义，会发生栈溢出，原因在于这超出了编译器对局部变量空间大小预设的值
    //vs2017 报错信息为：0x00B91899 处有未经处理的异常(在 FZUOJ.exe 中): 0xC00000FD: Stack overflow (参数: 0x00000000, 0x002E2000)。
	while (scanf("%d", &R) != EOF) {
		for (i = 0; i < R; i++) {
			for (j = 0; j < i + 1; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = R - 2; i >= 0; i--) {
			for (j = 0; j < i + 1; j++) {
				a[i][j] = max(a[i + 1][j], a[i + 1][j + 1]) + a[i][j];
			}
		}
		printf("%d\n", a[0][0]);
	}
}
```

