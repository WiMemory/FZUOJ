# Problem 1068 An Interesting Set

### Accept: 641    Submit: 1172 Time Limit: 1000 mSec    Memory Limit : 32768 KB

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Problem Description

Thomas, a mathematician, is interested in a set S consisting of positive integers. Set S is defined as follows:

(1) If a positive integer satisfies the property that the sum of all digits of it is equal to the product of them, then it belongs to S. 

(2) If m belongs to S, then 2m belongs to S. Thomas wants to find out the Kth smallest integer in set S. Design a program to solve the problem.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Input

The first line in the input is an integer N representing the number of test cases. The following N lines are N test cases and each line contains an integer K (1<=K<=500).

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Output

For each test case, output a line containing an integer that is the Kth smallest integer in set S.

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Input

>2
>
>5
>
>16

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Sample Output

> 5
>
> 22

## ![img](http://acm.fzu.edu.cn/image/prodesc.gif) Source

FJNUPC 2005

## 解决方案

使用打表的方法

让i从1开始判断，直到得到500个符合条件的数值，存入数组S

判断的条件有两个，一是判断i是否是S中原有数值的2倍，二是判断i的各位数字的总和是否和乘积相等

判断条件一可以利用set迅速查找指定key值的特性

判断条件二利用取余即可

```cpp
int num[505];
set<int> s;
set<int>::iterator it;
bool isin(int a) {
	int total = 0, muti = 1;
	int num;
	//条件一，需要判断是否偶数
	if (a % 2 == 0) {
		//否则 11 / 2 = 5，即所有数字都会被认为符合条件一
		it = s.find(a / 2);
		if (it != s.end()) {
			return true;
		}
	}
	//条件二
	while (a) {
		num = a % 10;
		if (num == 0) {
			return false;
		}
		total += num;
		muti *= num;
		a /= 10;
	}
	if (total != muti) {
		return false;
	}
	return true;
}
//打表初始化
void init() {
	int i, j;
	for (i = 1, j = 1; j <= 500; i++) {
		if (isin(i)) {
			num[j++] = i;
			s.insert(set<int>::value_type(i));
		}
	}
}
int main() {
	int N, k;
	cin >> N;
	init();
	while (N--) {
		cin >> k;
		cout << num[k] << endl;
	}
}
```

