# Problem 1012 Relatives

### Accept: 779    Submit: 2271 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

Given *n*, a positive integer, how many positive integers less than *n* are relatively prime to *n*? Two integers *a* and *b* are relatively prime if there are no integers *x > 1, y > 0, z > 0* such that *a = xy* and *b = xz*.

There are several test cases. For each test case, standard input contains a line with *n <= 1,000,000,000*. A line containing 0 follows the last case.

For each test case there should be single line of output answering the question posed above.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 7
>
> 12
>
> 0

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 6
>
> 4

## 解决方案

题意既是要求欧拉函数，属于数论的基础问题，后续可用于快速幂以求解高次幂

> [浅谈欧拉函数](https://blog.csdn.net/liuzibujian/article/details/81086324)

```cpp
#include<iostream>
#include<math.h>
using namespace std;
int ol(int x) {
	int i, ans = x;
	for (i = 2; i * i <= x; i++) {
		if (x%i == 0) {
			ans = ans - ans / i;
			while (x%i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		ans = ans - ans / x;
	}
	return ans;
}
int main() {
	int n, ans, i, j;
	while (scanf("%d", &n) != EOF && n != 0) {
		printf("%d\n", ol(n));
	}

	return 0;
}
```

