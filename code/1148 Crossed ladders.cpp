#include <cstdio>
#include <cmath>
double x, y, c;
bool judge(double o)
{
	double tmp1 = sqrt(x*x - o * o);
	double tmp2 = sqrt(y*y - o * o);
	if (tmp1*tmp2 >= c * (tmp1 + tmp2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
double min(double x, double y)
{
	return x < y ? x : y;
}
int main()
{
	while (scanf("%lf%lf%lf", &x, &y, &c)!=EOF)
	{
		
		double l = 0, r = min(x, y);//直角边不会大于斜边
		int size = 100;
		double mid;
		while (size--)
		{
			mid = (l + r) / 2.0;
			if (judge(mid))
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		printf("%.3lf\n", mid);
	}
	return 0;
}