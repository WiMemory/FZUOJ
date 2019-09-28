# Problem 1147 Tiling

### Accept: 495    Submit: 1261 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

In how many ways can you tile a 2x*n* rectangle by 2x1 or 2x2 tiles?

Here is a sample tiling of a 2x17 rectangle.




![img](http://acm.fzu.edu.cn/image/Problem/1147.gif)



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

Input is a sequence of lines, each line containing an integer number *0 <= n <= 250*.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each line of input, output one integer number in a separate line giving the number of possible tilings of a 2x*n* rectangle.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 2
>
> 8
>
> 12

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 3
>
> 171
>
> 2731 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

Albert 2001

## 解决方案

找规律

由于n的范围太大了，long long都存不下，所以要用到大数相加

F(n)=F(n-2)*2+F(n-1)

F(0)=1 F(1)=1 F(2)=3

```cpp
#include<iostream>
using namespace std;
int F[251][100];
void init() {
	memset(F, 0, sizeof(F));
	F[1][0] = 1;
	F[2][0] = 3;
	int i, c, j;
	for (i = 3; i <= 250; i++) {
		c = 0;
		for (j = 0; j <= 100; j++)
		{
			F[i][j] = F[i - 1][j] + 2 * F[i - 2][j] + c;
			c = F[i][j] / 10;
			F[i][j] %= 10;
		}
	}
}
int main() {
	int n, i, j;
	init();
	while (cin >> n) {
		if (n == 0)
			cout << 1 << endl;
		else
		{
			for (i = 99; i >= 0; i--)
				if (F[n][i])
					break;
			for (j = i; j >= 0; j--)
				cout << F[n][j];
			cout << endl;
		}
	}
}
```

