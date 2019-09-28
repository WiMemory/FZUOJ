# Problem 1160 Common Subsequence

### Accept: 484    Submit: 1027 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = <x1, x2, ..., xm> another sequence Z = <z1, z2, ..., zk> is a subsequence of X if there exists a strictly increasing sequence <i1, i2, ..., ik> of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = <a, b, f, c> is a subsequence of X = <a, b, c, f, b, c> with index sequence <1, 2, 4, 6>. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

The program input is from a text file. Each data set in the file contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.



## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

> abcfbc abfcab
> programming contest 
> abcd mnp

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 4
>
> 2
>
> 0

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

SEERC 2003

## 解决方案

LCS动态规划

理论：<https://blog.csdn.net/someone_and_anyone/article/details/81044153>

本题不要求输出LCS序列，故只要懂得LCS的状态转移方程即可

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
char s1[1005], s2[1005];
int l1, l2, dp[1005][1005];
int main() {
	while (~scanf("%s%s", s1 + 1, s2 + 1)) {
		l1 = strlen(s1 + 1);
		l2 = strlen(s2 + 1);
		for (int i = 0; i <= l2; i++)
			dp[0][i] = 0;
		for (int i = 0; i <= l1; i++)
			dp[i][0] = 0;
		for (int i = 1; i <= l1; i++)
			for (int j = 1; j <= l2; j++) {
				if (s1[i] == s2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		printf("%d\n", dp[l1][l2]);
	}
	return 0;
}
```

