//��Դhttps://blog.csdn.net/suifengdream/article/details/8590581
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
		for (i = 0; i < n; i++)//��������
			scanf("%s", A[i]);
		for (i = 0; i < n; i++)
		{//Ԥ����
			for (j = 0; j < n; j++)
			{
				if (A[i][j] == '.')
				{//��B[i][j]�Ĵ�����B[i][j]����õ�λ�������໥Ӱ��ĵ�λ�ĸ���
					for (k = i - 1; k >= 0 && A[k][j] == '.'; k--)//�ϱ�
						B[i][j]++;
					for (k = i + 1; k < n && A[k][j] == '.'; k++)//�±�
						B[i][j]++;
					for (k = j - 1; k >= 0 && A[i][k] == '.'; k--)//���
						B[i][j]++;
					for (k = j + 1; k < n && A[i][k] == '.'; k++)//�ұ�
						B[i][j]++;
					B[i][j]++;//�Լ�Ӱ���Լ�
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
				{//�ҵ���Сֵ������
					min = B[i][j];
					a = i;
					b = j;
				}
			}
			if (min != 8)
			{
				cnt++;//�ҵ�һ������������λ��
				for (k = a - 1; k >= 0 && A[k][b] == '.'; k--)//�ϱ�
					B[k][b] = 8;//��Ϊ���ͼ��4*4��ͼ��һ�����������Ӱ�������7������
				for (k = a + 1; k < n && A[k][b] == '.'; k++)//�±�
					B[k][b] = 8;
				for (k = b - 1; k >= 0 && A[a][k] == '.'; k--)//���
					B[a][k] = 8;
				for (k = b + 1; k < n && A[a][k] == '.'; k++)//�ұ�
					B[a][k] = 8;
				B[a][b] = 8;
				i--;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}