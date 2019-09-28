# Problem 1759 Super A^B mod C

### Accept: 1877    Submit: 6419 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

Given A,B,C, You should quickly calculate the result of A^B mod C. (1<=A,C<=1000000000,1<=B<=10^1000000).

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

There are multiply testcases. Each testcase, there is one line contains three integers A, B and C, separated by a single space.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each testcase, output an integer, denotes the result of A^B mod C.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 3 2 4
>
> 2 10 1000 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

>  1
>
> 24 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

FZU 2009 Summer Training IV--Number Theory

## 解决思路1

```cpp
#include<iostream>
int main() {
	int A, C, ans;
	__int64 B, i;
	while (scanf("%d %I64d %d", &A, &B, &C) != EOF) {
		ans = A;
		for (i = 0; i < B-1; i++) {
			ans = (ans*A) % C;
		}
		printf("%d\n", ans);
	}
}
```

Time Limit Exceed

## 解决思路2

知识点一：**快速幂**

> 假设我们要求a<sup>b</sup>，按照朴素算法就是把a连乘b次，这样一来时间复杂度是O(b)，即是O(n)级别。但快速幂能做到O(logn)的复杂度。
>
> 快速幂：
>
> 先上实现快速幂运算的具体代码：
>
> ```cpp
> int qsm(int a, int b)
> {
> 	int ans = 1, base = a;
> 	while (b != 0) {
> 		if (b & 1 != 0) {
> 			ans *= base;
> 		}
> 		base *= base;
> 		b >>= 1;
> 	}
> 	return ans;
> }
> ```
>
>
> 其中“b & 1”指取b的二进制数的最末位，如11的二进制数为1011，第一次循环，取的是最右边的“1” ，以此类推。
>
> 而“b >>= 1”等效于b = b >> 1，即右移1位，删去最低位。
>
> 以a<sup>11</sup>为例：
>
> b的二进制数为1011，二进制从右向左算，但乘出来的顺序是 a<sup>2<sup>0</sup></sup> *a<sup>2<sup>1</sup></sup> *a<sup>2<sup>3</sup></sup>，是从左向右的。我们不断的让base *= base目的是累乘，以便随时对ans做出贡献。
>
> 其中要理解base *=base这一步：因为 base *base==base<sup>2</sup>，下一步再乘，就是base<sup>2</sup> *base<sup>2</sup>==base<sup>4</sup>，然后同理  base<sup>4</sup> *base<sup>4</sup>=base<sup>8</sup>，由此可以做到base-->base<sup>2</sup>-->base<sup>4</sup>-->base<sup>8</sup>-->base<sup>16</sup>-->base<sup>32</sup>.......指数正是 2<sup>i</sup> ，再看上面的例子，a<sup>11</sup>= a<sup>1</sup> *a<sup>2</sup> *a<sup>8</sup>，这三项就可以完美解决了，快速幂就是这样。
>
> 注意：由于指数函数是爆炸增长的函数，所以很有可能会爆掉int的范围，可根据题意选择 long long。

知识点二：**欧拉函数**

> [浅谈欧拉函数](https://blog.csdn.net/liuzibujian/article/details/81086324)

```cpp
//求解欧拉函数
#typedef __int64 ll
ll ol(ll x)
{
	ll i,res=x;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			res=res-res/i;
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1)
		res=res-res/x;
	return res;
}
```

知识点三：**降幂公式**

![img](http://images2015.cnblogs.com/blog/786945/201611/786945-20161122214248346-633478961.gif)

有了以上的知识储备，这题就有机会AC啦。

``` cpp
#include<iostream>
typedef __int64 ll;
const int max = 1e6 + 10;
char B[max];
ll A, C;
//快速幂
ll qsm(ll base, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1 != 0) {
			ans = ans * base%C;
		}
		base = base * base%C;
		n >>= 1;
	}
	return ans;
}
//欧拉函数
ll ol(ll x) {
	ll i, ans = x;
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
	ll i, b, ans, tmp;
	while (scanf("%I64d%s%I64d", &A, B, &C) != EOF)
	{
		ans = 0; b = 0; tmp = ol(C);
		ll len = strlen(B);
		//字符按位转为整数并取模
		for (i = 0; i < len; i++)
			b = (b * 10 + B[i] - '0') % tmp;
		b += tmp;
		ans = qsm(A, b);
		printf("%I64d\n", ans);
	}
}
```

