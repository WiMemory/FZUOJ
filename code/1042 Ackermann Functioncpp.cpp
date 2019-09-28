#include <stdio.h>
#include <math.h>
int main()
{
	int m, n, i;
	int sum;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		if (m == 1)
		{
			printf("%d\n", 2 + n);
		}
		else if (m == 2)
		{
			printf("%d\n", 3 + n * 2);
		}
		else if (m == 3)
		{
			if (n == 0)
			{
				printf("5\n");
				continue;
			}
			sum = 13;
			for (i = 1; i < n; i++)
				sum += (int)pow(2, 3 + i);
			printf("%d\n", sum);
		}
	}
	return 0;
}