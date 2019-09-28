#include<stdio.h>
int main()
{
	int w, h, l;
	int x[55], y[55];
	int i;
	int ans;
	while (scanf("%d%d", &w, &h) != EOF && w != 0 && h != 0)
	{
		//开始若有两条线则必定把矩形分成3块，且中间没有交点
		ans = 3;
		scanf("%d\n", &l);
		for (i = 0; i <= l; i++)
			scanf("%d%d", &x[i], &y[i]);
		if (l < 3)//当矩形中的线段小于三条时，分得的面积，就是线段数加上1;
		{
			ans = l + 1;
			printf("%d\n", ans);
			continue;
		}
		else
		{
			//当矩形中的线段大于三条时，每多出一条线，就会多出一个面，
			//然后多出的这条线与前面所有的线像比，若多出一个交点则，多出一个面
			for (i = 3; i <= l; i++)
			{
				ans++;
				int k = i - 2;
				//跨立试验，利用叉积判断是否相交
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