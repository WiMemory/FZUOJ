#include<stdio.h>
int main()
{
	int w, h, l;
	int x[55], y[55];
	int i;
	int ans;
	while (scanf("%d%d", &w, &h) != EOF && w != 0 && h != 0)
	{
		//��ʼ������������ض��Ѿ��ηֳ�3�飬���м�û�н���
		ans = 3;
		scanf("%d\n", &l);
		for (i = 0; i <= l; i++)
			scanf("%d%d", &x[i], &y[i]);
		if (l < 3)//�������е��߶�С������ʱ���ֵõ�����������߶�������1;
		{
			ans = l + 1;
			printf("%d\n", ans);
			continue;
		}
		else
		{
			//�������е��߶δ�������ʱ��ÿ���һ���ߣ��ͻ���һ���棬
			//Ȼ��������������ǰ�����е�����ȣ������һ�������򣬶��һ����
			for (i = 3; i <= l; i++)
			{
				ans++;
				int k = i - 2;
				//�������飬���ò���ж��Ƿ��ཻ
				while (k > 0)
				{
					int s1 = (x[i - 1] - x[k - 1])*(y[k] - y[k - 1]) - (y[i - 1] - y[k - 1])*(x[k] - x[k - 1]);
					int s2 = (x[k] - x[k - 1])*(y[i] - y[k - 1]) - (y[k] - y[k - 1])*(x[i] - x[k - 1]);
					if (s1*s2 > 0)
						ans++;
					k--;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}