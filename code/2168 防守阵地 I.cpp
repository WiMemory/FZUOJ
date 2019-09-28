#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1000010
int a[maxn], b[maxn];
int main()
{
	int n, m, i;
	__int64 ans, x, temp;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = b[i - 1] + a[i]; //保存前i个数的和
			if (i <= m) ans += a[i] * i;  //1-m个士兵的能力指数
		}
		x = ans;
		for (i = m + 1; i <= n; i++)
		{
			temp = x + (m + 1)*a[i]; //多加一次a[i]
			temp -= b[i] - b[i - m - 1]; //由于b[i]包括了a[i],等于这多减了一次，所以上面多加一次
			x = temp; //传递到下一阶段
			ans = max(temp, ans); //不断更新取最大值
		}
		printf("%I64d\n", ans);
	}
	return 0;
}