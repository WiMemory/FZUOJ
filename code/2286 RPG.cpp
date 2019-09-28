#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define eps 0.0000000001
const int maxn = 1e5 + 100;
double dis(double x, double y)
{
	return sqrt((y - 100)*(y - 100) + x * x);
}
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int ans = 0;
		double x, y, v;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", &x, &y, &v);
			double t = dis(x, y) / v;
			if (t < 100) ans++;
			else if (fabs(t - 100) <= eps) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}