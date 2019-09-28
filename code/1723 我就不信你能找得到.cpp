#include<stdio.h>
#include<algorithm>
using namespace std;
__int64 a[1000002];
int main()
{
	__int64 m, n, i, j, s, k, t;
	scanf("%I64d", &t);
	while (t--)
	{
		scanf("%I64d", &n);
		s = 0;
		for (i = 0; i < n; i++) {
			scanf("%I64d", &a[i]);
			s ^= a[i];
		}
		//此时的s是两个为奇数次数的数的异或
		//接下来要将s与两个奇数次数的数其中之一进行一次异或，便可以得到其中一个奇数
		//又因为s的二进制中第i位如果为1则这两个奇数的第i位必然一个为1另一个为0
		//所以遍历所有输入的第i位为1的所有数都与s进行异或，便可以得到其中一个奇数
		m = s, k = s, j = 0;
		//找到m二进制右数第一位1
		while (m) {
			j++;
			if (m % 2 == 1) break;
			m /= 2;
		}
		j--;
		for (i = 0; i < n; i++)
			if (a[i] >> j & 1)
				s ^= a[i];
		k ^= s;
		printf("%I64d %I64d\n", min(k, s), max(k, s));
	}
	return 0;
}