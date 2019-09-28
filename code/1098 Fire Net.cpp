//来源https://blog.csdn.net/suifengdream/article/details/8590581
#include <stdio.h>
#include <string.h>

char A[5][5];
int B[5][5];

int main()
{
	int n, i, j, k, cnt, a, b, min;
	while (scanf("%d", &n) && n)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for (i = 0; i < n; i++)//数据输入
			scanf("%s", A[i]);
		for (i = 0; i < n; i++)
		{//预处理
			for (j = 0; j < n; j++)
			{
				if (A[i][j] == '.')
				{//对B[i][j]的处理，令B[i][j]代表该单位与其他相互影响的单位的个数
					for (k = i - 1; k >= 0 && A[k][j] == '.'; k--)//上边
						B[i][j]++;
					for (k = i + 1; k < n && A[k][j] == '.'; k++)//下边
						B[i][j]++;
					for (k = j - 1; k >= 0 && A[i][k] == '.'; k--)//左边
						B[i][j]++;
					for (k = j + 1; k < n && A[i][k] == '.'; k++)//右边
						B[i][j]++;
					B[i][j]++;//自己影响自己
				}
			}
		}
		cnt = 0;
		for (i = 0; i < n; i++)
		{
			min = 8;
			for (j = 0; j < n; j++)
			{
				if (B[i][j] > 0 && min > B[i][j])
				{//找到最小值的坐标
					min = B[i][j];
					a = i;
					b = j;
				}
			}
			if (min != 8)
			{
				cnt++;//找到一个满足条件的位置
				for (k = a - 1; k >= 0 && A[k][b] == '.'; k--)//上边
					B[k][b] = 8;//因为大的图是4*4的图，一个方格最多能影响另外的7个方格
				for (k = a + 1; k < n && A[k][b] == '.'; k++)//下边
					B[k][b] = 8;
				for (k = b - 1; k >= 0 && A[a][k] == '.'; k--)//左边
					B[a][k] = 8;
				for (k = b + 1; k < n && A[a][k] == '.'; k++)//右边
					B[a][k] = 8;
				B[a][b] = 8;
				i--;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}