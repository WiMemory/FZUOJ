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
			b[i] = b[i - 1] + a[i]; //����ǰi�����ĺ�
			if (i <= m) ans += a[i] * i;  //1-m��ʿ��������ָ��
		}
		x = ans;
		for (i = m + 1; i <= n; i++)
		{
			temp = x + (m + 1)*a[i]; //���һ��a[i]
			temp -= b[i] - b[i - m - 1]; //����b[i]������a[i],����������һ�Σ�����������һ��
			x = temp; //���ݵ���һ�׶�
			ans = max(temp, ans); //���ϸ���ȡ���ֵ
		}
		printf("%I64d\n", ans);
	}
	return 0;
}