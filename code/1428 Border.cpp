#include<stdio.h>
#include<string.h>
int main()
{
	char ch[33][33], d;
	int i, j, x, y, k, n;
	scanf("%d", &n);
	k = 0;
	while (n--)
	{
		scanf("%d%d", &x, &y);
		for (i = 1; i <= 32; i++)
			for (j = 1; j <= 32; j++)
				ch[i][j] = '.';
		scanf("%c", &d);
		while (d != '.')
		{
			if (d == 'E')
			{
				x++;
				ch[32 - y + 1][x] = 'X';
			}
			if (d == 'N')
			{
				y++;
				ch[32 - y + 1][x + 1] = 'X';
			}
			if (d == 'W')
			{
				ch[32 - y][x] = 'X';
				x--;
			}
			if (d == 'S')
			{
				ch[32 - y + 1][x] = 'X';
				y--;
			}
			scanf("%c", &d);
		}
		k++;
		printf("Bitmap #%d\n", k);
		for (i = 1; i <= 32; i++)
		{
			for (j = 1; j <= 32; j++) printf("%c", ch[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}