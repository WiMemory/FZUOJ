#include<stdio.h>
#include<math.h>
long long s(long long n, long long m)
{
	long long sum = 0;
	while (n)
	{
		sum += n % m;
		n = n / m;
	}
	return sum;
}
int main()
{
	int t, flag;
	long long i, n, m, x;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%I64d%I64d", &n, &m);
		flag = 0;
		for (i = 1; i <= 100; i++)
		{
			x = (long long)(-i / 2 + sqrt(i*i + 4 * n) / 2);
			if (x*x + s(x, m)*x == n)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("-1\n");
		else
			printf("%I64d\n", x);
	}
	return 0;
}