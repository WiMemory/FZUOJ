#include <stdio.h>

int main()
{
	int arr[1001];
	int n, i, j, m;
	int count;
	while (scanf("%d", &n) != EOF, n != 0)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		count = 1;
		for (i = 1; i < n; i++)
		{
			if (count == 127)
			{
				printf("%d ", (arr[i - 1] << 7) + count);
				count = 1;
				continue;
			}
			if (arr[i] == arr[i - 1])
			{
				count++;
				continue;
			}
			else {
				printf("%d ", (arr[i - 1] << 7) + count);
				count = 1;
			}
		}
		printf("%d", (arr[i - 1] << 7) + count);
		printf("\n");
	}
	return 0;
}