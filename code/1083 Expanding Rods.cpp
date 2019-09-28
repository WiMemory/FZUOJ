#include <stdio.h>
#include <math.h>

int main()
{
	double n, C;
	double l;
	double L;
	double degree1, degree2, degree;
	while (scanf("%lf%lf%lf", &l, &n, &C) != EOF)
	{
		if (l == -1 || n == -1 || C == -1)
			break;
		L = l * (1 + n * C);
		if (n*C == 0)
		{
			printf("0.000\n");
			continue;
		}
		else
		{
			degree1 = 0;
			degree2 = acos(-1) / 2;
			while (degree2 - degree1 > 1e-12)
			{
				degree = (degree1 + degree2) / 2;
				if (l / L - sin(degree) / degree > 0)
				{
					degree2 = degree;
				}
				else
				{
					degree1 = degree;
				}
			}
			printf("%0.3lf\n", (l / (2 * sin(degree)) - l / (2 * tan(degree))));
		}
	}
	return 0;
}