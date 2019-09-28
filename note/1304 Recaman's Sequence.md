# Problem 1304 Recaman's Sequence

### Accept: 699    Submit: 2020 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

The Recaman's sequence is defined by a(0)=0; for m>0, a(m)=a(m-1)-m if the resulting a(m) is positive and not already in the sequence, otherwise a(m)=a(m-1)+m.

The first few numbers in the Recaman's Sequence is 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9, ...

Given k, your task is to calculate a(k).

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

The input consists of several test cases. Each line of the input contains an integer k where 0<=k<=500000.

The last line contains an integer -1, which should not be processed.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each k given in the input, print one line containing a(k) to the output.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 7
>
> 10000
>
> -1 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 20
>
> 18658 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

Shanghai2004 Preliminary

## 解决方案

模拟，注意a(k)的最大值

```cpp
#include<iostream>
//int MAXN = 0;
int a[500001] = { 0 };
bool visit[3012501] = { 0 }; //a[k]的最大值为3012500
int main() {
	int i;
	for (i = 1; i <= 500000; i++) {
		if (a[i - 1] - i > 0 && !visit[a[i - 1] - i]) {
			a[i] = a[i - 1] - i;
		}
		else a[i] = a[i - 1] + i;
		visit[a[i]] = 1;
		//if (a[i] > MAXN) MAXN = a[i];
	}
	//printf("%d\n", MAXN);
	while (scanf("%d", &i) != EOF) {
		if (i < 0) break;
		printf("%d\n", a[i]);
	}
}
```

