# include "stdio.h"
# include "string.h" 
char a[1000100];
int main()
{
	int i, j, k;
	int length;
	int flage;
	while (scanf("%s", a))
	{
		if (a[0] == '.')
		{
			break;
		}
		length = strlen(a);
		for (i = 1; i <= length; i++)//枚举周期串长度
		{
			if (length%i == 0)
			{
				flage = 1;
				for (k = i; k <= length - 1; k++)
				{
					if (a[k%i] != a[k])
					{
						flage = 0;
						break;
					}
				}
				if (flage)
				{
					printf("%d\n", length / i);
					break;
				}
			}
		}
	}
	return 0;
}