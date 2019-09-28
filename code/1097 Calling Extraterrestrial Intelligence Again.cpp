#include<iostream>
#include<math.h>
using namespace std;
int isprime(int n)
{
	int i;
	for (i = 3; i <= sqrt(n*1.0);)
	{
		if (n%i == 0)return 0;
		i = i + 2;
	}
	return 1;
}
int main()
{
	double mat[10001];
	int i, j, k;
	int m;
	int max;
	double a, b;
	int p, q;
	mat[0] = 2; j = 1;//最小的素数
	for (i = 3; i < 40000;)
	{
		if (isprime(i))//先把素数结果提前求出来
		{
			mat[j] = i;
			j++;
		}
		i = i + 2;//偶数直接排除
	}
	while (scanf("%d%lf%lf", &m, &a, &b) != EOF)
	{
		max = 0;
		if (!m && !a && !b)break;
		for (i = 0; i < j; i++)
		{
			for (k = 0; k < j; k++)
			{

				if ((mat[i] / mat[k]) < (a / b))break;
				if (mat[k] * mat[i] > m)break;
				if ((mat[i] / mat[k]) <= 1 && mat[k] * mat[i] > max)
				{
					max = mat[k] * mat[i];
					p = mat[k];
					q = mat[i];
				}
			}
			if (mat[i] * 2 > m)break;
		}
		printf("%d %d\n", q, p);
	}
	return 0;
}