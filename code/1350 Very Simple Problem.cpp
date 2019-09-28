#include<iostream>
#include<stdio.h>
using namespace std;
int a[150][150];
int c[150], d[150];
int ans[150], tn;
int main()
{
	int n, p;
	int tp, tmax;
	while (scanf("%d%d", &n, &p) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			tp = 1001;
			tmax = 0;
			for (int j = 0; j < p; j++)
			{
				scanf("%d", &a[i][j]);
				if (a[i][j] < tp)
					tp = a[i][j];
				if (a[i][j] > tmax)
					tmax = a[i][j];
			}
			c[i] = tp;
			d[i] = tmax;
		}
		tn = 0;
		for (int i = 0; i < p; i++)
		{
			tp = 0;
			for (int j = 0; j < n; j++)
			{
				if (a[j][i] == c[j])
					tp++;
				if (a[j][i] == d[j])
				{
					tp = 0;
					break;
				}
			}
			if (tp > n / 2)
				ans[tn++] = i + 1;
		}
		if (tn == 0)
			printf("0");
		for (int i = 0; i < tn; i++)
		{
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}