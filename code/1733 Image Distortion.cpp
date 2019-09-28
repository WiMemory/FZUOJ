#include <stdio.h>
int main()
{
	int n, m, i, j, sum;
	char a[100][101], b;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		sum = 0;
		for (i = 0; i < n; i++)
			scanf("%s", a[i]);
		getchar();
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%c", &b);
				if (a[i][j] != b)
					sum++;
			}
			getchar();
		}
		printf("%d\n", sum);
	}
	return 0;
}