#include"stdio.h"
#include"string.h"

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b)!=EOF&&a!=0&&b!=0)
	{
		int ans = 1;
		for (int i = 0; i < b; i++)
		{
			ans = (ans*(a % 9)) % 9;
		}
		if (ans)
			printf("%d\n", ans);
		else
			printf("9\n");
	}
	return 0;
}