# Problem 1148 Crossed ladders

### Accept: 205    Submit: 398 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

A narrow street is lined with tall buildings. An *x* foot long ladder is rested at the base of the building on the right side of the street and leans on the building on the left side. A *y* foot long ladder is rested at the base of the building on the left side of the street and leans on the building on the right side. The point where the two ladders cross is exactly *c* feet from the ground. How wide is the street?




![img](http://acm.fzu.edu.cn/image/Problem/1148.gif)



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

Each line of input contains three positive floating point numbers giving the values of *x*, *y*, and *c*.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each line of input, output one line with a floating point number giving the width of the street in feet, with three decimal digits in the fraction.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> 30 40 10
>
> 12.619429 8.163332 3
>
> 10 10 3
>
> 10 10 1 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 26.033
>
> 7.000
>
> 8.000
>
> 9.798 

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

Albert 2001

## 解决方案

![1148](.\1148.png)

采用二分逼近方法求出D

```cpp
#include <cstdio>
#include <cmath>
double x, y, c;
bool judge(double o)
{
	double tmp1 = sqrt(x*x - o * o);
	double tmp2 = sqrt(y*y - o * o);
	if (tmp1*tmp2 >= c * (tmp1 + tmp2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
double min(double x, double y)
{
	return x < y ? x : y;
}
int main()
{
	while (scanf("%lf%lf%lf", &x, &y, &c)!=EOF)
	{
		
		double l = 0, r = min(x, y);//直角边不会大于斜边
		int size = 100;
		double mid;
		while (size--)
		{
			mid = (l + r) / 2.0;
			if (judge(mid))
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		printf("%.3lf\n", mid);
	}
	return 0;
}
```

