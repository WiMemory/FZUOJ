#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
#define maxn 5000505
int f[maxn];    //������飻
int main()
{
	int t, flag = 1, ans = 1, step = 2;
	memset(f, 0, sizeof(f));
	f[1] = 1;
	for (int i = 2; i <= maxn; i++)
	{
		f[i] = step;    //step ��¼ �ڼ��У�
		if (step > ans)
			ans++;    // ��step�Ƚϣ����Ƿ���ͬһ��;
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
		if (x == y)     //  ����;
		{
			printf("Case %d:No\n", flag++);
			continue;
		}
		if (x < y)
			swap(x, y);        // ��x��Ϊ����Ǹ�;
		if (f[x - 1] == f[x] - 1)    // ���x��������ߵ���һ��;
		{
			if (y == x - f[x - 1])
				cmcc = 1;
		}
		else if (f[x] + 1 == f[x + 1])//���x�������ұ���һ��;
		{
			if (y == x - 1 || y == x - f[x])
				cmcc = 1;
		}
		else if (f[x] - 1 == f[y])  // ���x��y�ڲ�ͬ��;
		{
			if (x == y + f[x] || x == y + f[y])
				cmcc = 1;
		}
		else if (f[x] == f[y])    // ���x��y��ͬһ��;
		{
			if (x == y + 1)
				cmcc = 1;
		}
		printf("Case %d:%s\n", flag++, cmcc == 1 ? "Yes" : "No");
	}
	return 0;
}
