# Problem 1002 HangOver

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

How far can you make a stack of cards overhang a table? If you have one card, you can create a maximum overhang of half a card length. (We're assuming that the cards must be perpendicular to the table.) With two cards you can make the top card overhang the bottom one by half a card length, and the bottom one overhang the table by a third of a card length, for a total maximum overhang of 1/2 + 1/3 = 5/6 card lengths. In general you can make n cards overhang by 1/2 + 1/3 + 1/4 + ... + 1/(n + 1) card lengths, where the top card overhangs the second by 1/2, the second overhangs tha third by 1/3, the third overhangs the fourth by 1/4, etc., and the bottom card overhangs the table by 1/(n + 1). This is illustrated in the figure below.

![img](http://acm.fzu.edu.cn/image/Problem/1002.gif)





## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

The input consists of one or more test cases, followed by a line containing the number 0.00 that signals the end of the input. Each test case is a single line containing a positive floating-point number c whose value is at least 0.01 and at most 5.20; c will contain exactly three digits.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each test case, output the minimum number of cards necessary to achieve an overhang of at least c card lengths. Use the exact output format shown in the examples.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

```
1.00
3.71
0.04
5.19
0.00 
```

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

``` 
3 card(s)
61 card(s)
1 card(s)
273 card(s)
```

## 解决思路1

题目限制了c的取值范围，即可采用打表方式获取更高的效率。

``` cpp
#include<iostream>

int main() {
	double length;
	double goal[279];
	goal[0] = 0;
	int i;
    //将所有可能情况存入数组goal
	for (i = 1; i < 278; i++) {
		goal[i] = goal[i - 1] + 1.00 / (i + 1);
	}
	while (scanf("%lf", &length) != EOF) {
		if (length == 0.00) {
			break;
		}
		for (i = 1; i <= 278; i++) {
			if (length <= goal[i]) {
				printf("%d card(s)\n", i);
				break;
			}
		}
	}
}
```
## 解决思路2

``` cpp
#include<iostream>

int main() {
	double length, goal;
	int i;
	while (scanf("%lf", &length) != EOF) {
		if (length == 0.00) {
			break;
		}
		goal = 0;
		for (i = 1; ; i++) {
			goal += 1.00 / (i + 1);
			if (length <= goal) {
				break;
			}
		}
		printf("%d card(s)\n", i);
	}
}
```

## 问题

将如上的double改为float则由AC变为WA，何解？

