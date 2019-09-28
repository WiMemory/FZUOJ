#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
#define maxn 5000505
int f[maxn];    //打表数组；
int main()
{
	int t, flag = 1, ans = 1, step = 2;
	memset(f, 0, sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= maxn; i++)
	{
		f[i] = step;    //step 记录 第几行；
		if (step > ans)
			ans++;    // 与step比较，看是否在同一行;
		else
		{
			step++;
			ans = 1;
		}
	}
	scanf("%d", &t);
	while (t--)
	{
		int x, y, cmcc = 0;
		scanf("%d%d", &x, &y);
		if (x == y)     //  特判;
		{
			printf("Case %d:No\n", flag++);
			continue;
		}
		if (x < y)
			swap(x, y);        // 让x成为大的那个;
		if (f[x - 1] == f[x] - 1)    // 如果x是在最左边的那一列;
		{
			if (y == x - f[x - 1])
				cmcc = 1;
		}
		else if (f[x] + 1 == f[x + 1])//如果x是在最右边那一列;
		{
			if (y == x - 1 || y == x - f[x])
				cmcc = 1;
		}
		else if (f[x] - 1 == f[y])  // 如果x，y在不同行;
		{
			if (x == y + f[x] || x == y + f[y])
				cmcc = 1;
		}
		else if (f[x] == f[y])    // 如果x，y在同一行;
		{
			if (x == y + 1)
				cmcc = 1;
		}
		printf("Case %d:%s\n", flag++, cmcc == 1 ? "Yes" : "No");
	}
	return 0;
}
