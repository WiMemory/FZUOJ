#include <stdio.h>
#define num 1005
double s[num];
int main()
{
	int n, t, i;
	while (scanf("%d", &n) == 1 && n)
	{
		double ave = 0, resultH = 0, resultL = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &s[i]);
			ave += s[i];
		}
		ave /= n;

		for (i = 0; i < n; i++)
			if (s[i] < ave)
				resultL += (int)((ave - s[i]) * 100) / 100.0;
			else
				resultH += (int)((s[i] - ave) * 100) / 100.0;
		printf("$%0.2lf\n", resultL < resultH ? resultH : resultL);
	}
	return 0;
}