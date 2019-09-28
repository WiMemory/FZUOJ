# Problem 1047 Lotto

### Accept: 534    Submit: 1234 Time Limit: 1000 mSec    Memory Limit : 65536 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

In the German Lotto you have to select 6 numbers from the set {1,2,...,49}.

A popular strategy to play Lotto - although it doesn't increase your chance of winning - is to select a subset S containing *k* (*k*>6) of these 49 numbers, and then play several games with choosing numbers only from S.



For example, for *k*=8 and S = 1,2,3,5,8,13,21,34 there are 28 possible games: [1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34].



Your job is to write a program that reads in the number k and the set S and then prints all possible games choosing numbers only from S.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

The input file will contain one or more test cases.

Each test case consists of one line containing several integers separated from each other by spaces. The first integer on the line will be the number *k* (6 < *k* < 13). Then *k* integers, specifying the set S, will follow in ascending order.

Input will be terminated by a value of zero (0) for *k*.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each test case, print all possible games, each game on one line.

The numbers of each game have to be sorted in ascending order and separated from each other by exactly one space. The games themselves have to be sorted lexicographically, that means sorted by the lowest number first, then by the second lowest and so on, as demonstrated in the sample output below.

The test cases have to be separated from each other by exactly one blank line. Do not put a blank line after the last test case.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 7 1 2 3 4 5 6 7
>
> 8 1 2 3 5 8 13 21 34
>
> 0 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 1 2 3 4 5 6
> 1 2 3 4 5 7
> 1 2 3 4 6 7
> 1 2 3 5 6 7
> 1 2 4 5 6 7
> 1 3 4 5 6 7
> 2 3 4 5 6 7
>
> 1 2 3 5 8 13
> 1 2 3 5 8 21
> 1 2 3 5 8 34
> 1 2 3 5 13 21
> 1 2 3 5 13 34
> 1 2 3 5 21 34
> 1 2 3 8 13 21
> 1 2 3 8 13 34
> 1 2 3 8 21 34
> 1 2 3 13 21 34
> 1 2 5 8 13 21
> 1 2 5 8 13 34
> 1 2 5 8 21 34
> 1 2 5 13 21 34
> 1 2 8 13 21 34
> 1 3 5 8 13 21
> 1 3 5 8 13 34
> 1 3 5 8 21 34
> 1 3 5 13 21 34
> 1 3 8 13 21 34
> 1 5 8 13 21 34
> 2 3 5 8 13 21
> 2 3 5 8 13 34
> 2 3 5 8 21 34
> 2 3 5 13 21 34
> 2 3 8 13 21 34
> 2 5 8 13 21 34
> 3 5 8 13 21 34

## 解决方案1

使用6重循环输出所有可能

```cpp
#include<iostream>
int a[20];
int main() {
	int n, t = 0, i, j, k, p, q, r;
	while (scanf("%d", &n) != EOF && n != 0) {
		if (t > 0) {
			printf("\n");
		}
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (i = 1; i <= n - 5; i++)
			for (j = i + 1; j <= n - 4; j++)
				for (k = j + 1; k <= n - 3; k++)
					for (p = k + 1; p <= n - 2; p++)
						for (q = p + 1; q <= n - 1; q++)
							for (r = q + 1; r <= n; r++)
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[k], a[p], a[q], a[r]);
		++t;
	}
	return 0;
}
```

## 解决方案2

作者：笑着走完自己的路 
原文：https://blog.csdn.net/chenzhenyu123456/article/details/47282969 